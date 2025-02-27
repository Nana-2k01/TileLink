// tilelink_cdc_adapter.sv
// CDC adapter bridging the 100 MHz (xbar_main) and 24 MHz (xbar_peri) domains.
// It uses separate asynchronous FIFOs (depth = FIFO_DEPTH) for Channel A (request)
// and Channel D (response). For simplicity, the bit-packing/unpacking is performed
// in a straightforward manner. (In a full design, ensure two synchronizer stages per FIFO.)
module tilelink_cdc_adapter #(
  parameter ADDR_WIDTH   = 32,
  parameter DATA_WIDTH   = 32,
  parameter MASK_WIDTH   = DATA_WIDTH/8,
  parameter SIZE_WIDTH   = 3,
  parameter SRC_WIDTH    = 2,
  parameter SINK_WIDTH   = 1,
  parameter OPCODE_WIDTH = 3,
  parameter PARAM_WIDTH  = 3,
  parameter FIFO_DEPTH   = 8,
  localparam CH_A_WIDTH = 1 + OPCODE_WIDTH + PARAM_WIDTH + SIZE_WIDTH + SRC_WIDTH + ADDR_WIDTH + MASK_WIDTH + DATA_WIDTH,
  localparam CH_D_WIDTH = 1 + OPCODE_WIDTH + PARAM_WIDTH + SIZE_WIDTH + SRC_WIDTH + SINK_WIDTH + DATA_WIDTH + 1
)(
  // 100 MHz side (input from xbar_main)
  input  logic clk_in,
  input  logic reset_in,
  // 24 MHz side (output toward xbar_peri)
  input  logic clk_out,
  input  logic reset_out,
  
  // Channel A signals (Request)
  input  logic a_valid_in,
  output logic a_ready_in,
  input  logic [OPCODE_WIDTH-1:0] a_opcode_in,
  input  logic [PARAM_WIDTH-1:0]  a_param_in,
  input  logic [SIZE_WIDTH-1:0]   a_size_in,
  input  logic [SRC_WIDTH-1:0]    a_source_in,
  input  logic [ADDR_WIDTH-1:0]   a_address_in,
  input  logic [MASK_WIDTH-1:0]   a_mask_in,
  input  logic [DATA_WIDTH-1:0]   a_data_in,
  
  output logic a_valid_out,
  input  logic a_ready_out,
  output logic [OPCODE_WIDTH-1:0] a_opcode_out,
  output logic [PARAM_WIDTH-1:0]  a_param_out,
  output logic [SIZE_WIDTH-1:0]   a_size_out,
  output logic [SRC_WIDTH-1:0]    a_source_out,
  output logic [ADDR_WIDTH-1:0]   a_address_out,
  output logic [MASK_WIDTH-1:0]   a_mask_out,
  output logic [DATA_WIDTH-1:0]   a_data_out,
  
  // Channel D signals (Response) from xbar_peri (24 MHz side)
  input  logic d_valid_in,
  output logic d_ready_in,
  input  logic [OPCODE_WIDTH-1:0] d_opcode_in,
  input  logic [PARAM_WIDTH-1:0]  d_param_in,
  input  logic [SIZE_WIDTH-1:0]   d_size_in,
  input  logic [SRC_WIDTH-1:0]    d_source_in,
  input  logic [SINK_WIDTH-1:0]   d_sink_in,
  input  logic [DATA_WIDTH-1:0]   d_data_in,
  input  logic d_error_in,
  
  output logic d_valid_out,
  input  logic d_ready_out,
  output logic [OPCODE_WIDTH-1:0] d_opcode_out,
  output logic [PARAM_WIDTH-1:0]  d_param_out,
  output logic [SIZE_WIDTH-1:0]   d_size_out,
  output logic [SRC_WIDTH-1:0]    d_source_out,
  output logic [SINK_WIDTH-1:0]   d_sink_out,
  output logic [DATA_WIDTH-1:0]   d_data_out,
  output logic d_error_out
);
  // ---------------- Channel A FIFO (100 MHz -> 24 MHz) ----------------
  // Pack Channel A signals into one bus.
  logic [CH_A_WIDTH-1:0] fifo_a_wr_data, fifo_a_rd_data;
  logic fifo_a_wr_en, fifo_a_rd_en;
  logic fifo_a_full, fifo_a_empty;
  
  assign fifo_a_wr_data = {a_valid_in, a_opcode_in, a_param_in, a_size_in,
                           a_source_in, a_address_in, a_mask_in, a_data_in};
  assign fifo_a_wr_en = a_valid_in && (!fifo_a_full);
  assign a_ready_in = !fifo_a_full;
  
  // Instantiate a simple asynchronous FIFO for Channel A.
  async_fifo #(
    .DATA_WIDTH(CH_A_WIDTH),
    .DEPTH(FIFO_DEPTH)
  ) fifo_a (
    .wr_clk(clk_in),
    .rd_clk(clk_out),
    .reset(reset_in),
    .wr_en(fifo_a_wr_en),
    .wr_data(fifo_a_wr_data),
    .full(fifo_a_full),
    .rd_en(fifo_a_rd_en),
    .rd_data(fifo_a_rd_data),
    .empty(fifo_a_empty)
  );
  
  // On the 24 MHz side, drive Channel A outputs.
  assign a_valid_out = !fifo_a_empty;
  assign fifo_a_rd_en = a_valid_out && a_ready_out;
  // For simulation, assume proper bit-slicing to extract fields:
  // {valid, opcode, param, size, source, address, mask, data}
  assign a_opcode_out  = fifo_a_rd_data[CH_A_WIDTH-1 -: OPCODE_WIDTH];
  assign a_param_out   = fifo_a_rd_data[CH_A_WIDTH-OPCODE_WIDTH-1 -: PARAM_WIDTH];
  assign a_size_out    = fifo_a_rd_data[CH_A_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-1 -: SIZE_WIDTH];
  assign a_source_out  = fifo_a_rd_data[CH_A_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-SIZE_WIDTH-1 -: SRC_WIDTH];
  assign a_address_out = fifo_a_rd_data[CH_A_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-SIZE_WIDTH-SRC_WIDTH-1 -: ADDR_WIDTH];
  assign a_mask_out    = fifo_a_rd_data[CH_A_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-SIZE_WIDTH-SRC_WIDTH-ADDR_WIDTH-1 -: MASK_WIDTH];
  assign a_data_out    = fifo_a_rd_data[DATA_WIDTH-1:0];  // Lowest bits
  
  // ---------------- Channel D FIFO (24 MHz -> 100 MHz) ----------------
  // Pack Channel D signals from the 24 MHz domain.
  logic [CH_D_WIDTH-1:0] fifo_d_wr_data, fifo_d_rd_data;
  logic fifo_d_wr_en, fifo_d_rd_en;
  logic fifo_d_full, fifo_d_empty;
  
  assign fifo_d_wr_data = {d_valid_in, d_opcode_in, d_param_in, d_size_in,
                           d_source_in, d_sink_in, d_data_in, d_error_in};
  assign fifo_d_wr_en = d_valid_in && (!fifo_d_full);
  assign d_ready_in = !fifo_d_full;
  
  async_fifo #(
    .DATA_WIDTH(CH_D_WIDTH),
    .DEPTH(FIFO_DEPTH)
  ) fifo_d (
    .wr_clk(clk_out),
    .rd_clk(clk_in),
    .reset(reset_out),
    .wr_en(fifo_d_wr_en),
    .wr_data(fifo_d_wr_data),
    .full(fifo_d_full),
    .rd_en(fifo_d_rd_en),
    .rd_data(fifo_d_rd_data),
    .empty(fifo_d_empty)
  );
  
  assign d_valid_out = !fifo_d_empty;
  assign fifo_d_rd_en = d_valid_out && d_ready_out;
  // Unpack FIFO D data (assuming proper bit slicing):
  assign d_opcode_out = fifo_d_rd_data[CH_D_WIDTH-1 -: OPCODE_WIDTH];
  assign d_param_out  = fifo_d_rd_data[CH_D_WIDTH-OPCODE_WIDTH-1 -: PARAM_WIDTH];
  assign d_size_out   = fifo_d_rd_data[CH_D_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-1 -: SIZE_WIDTH];
  assign d_source_out = fifo_d_rd_data[CH_D_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-SIZE_WIDTH-1 -: SRC_WIDTH];
  assign d_sink_out   = fifo_d_rd_data[CH_D_WIDTH-OPCODE_WIDTH-PARAM_WIDTH-SIZE_WIDTH-SRC_WIDTH-1 -: SINK_WIDTH];
  assign d_data_out   = fifo_d_rd_data[DATA_WIDTH-1:0];  // Lowest bits
  assign d_error_out  = fifo_d_rd_data[0];  // Assuming error is the LSB
  
endmodule
