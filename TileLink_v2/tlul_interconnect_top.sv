// tlul_interconnect_top.sv
// Top-level interconnect for TL-UL.
// This module instantiates:
//   - xbar_main (operating at 100 MHz) which arbitrates among NUM_MASTERS master sockets.
//   - A TileLink-to-TileLink CDC adapter (with separate async FIFOs) bridging the 100 MHz domain to the 24 MHz domain.
//   - xbar_peri (operating at 24 MHz) which exposes the slave socket.
// The master and slave interfaces are left open for external stimuli (testbench).
module tlul_interconnect_top #(
  parameter ADDR_WIDTH   = 32,
  parameter DATA_WIDTH   = 32,
  parameter MASK_WIDTH   = DATA_WIDTH/8,      // 4-bit mask for 32-bit data.
  parameter SIZE_WIDTH   = 3,                 // TL-UL size field (3 bits).
  parameter SRC_WIDTH    = 2,                 // Enough for 3 masters.
  parameter SINK_WIDTH   = 1,
  parameter OPCODE_WIDTH = 3,                 // TL-UL opcode width.
  parameter PARAM_WIDTH  = 3,
  parameter NUM_MASTERS  = 3,
  parameter FIFO_DEPTH   = 8
)(
  // Clocks and reset.
  input  logic clk_100,    // 100 MHz domain (xbar_main)
  input  logic clk_24,     // 24 MHz domain (xbar_peri and slave)
  input  logic reset,
  
  // --------------------- Master Socket Interface ---------------------
  // These ports are used to inject stimuli in place of CPU/accelerators.
  
  // Channel A (Request) from masters.
  input  logic [NUM_MASTERS-1:0] master_a_valid,
  output logic [NUM_MASTERS-1:0] master_a_ready,
  input  logic [NUM_MASTERS*OPCODE_WIDTH-1:0] master_a_opcode,
  input  logic [NUM_MASTERS*PARAM_WIDTH-1:0]  master_a_param,
  input  logic [NUM_MASTERS*SIZE_WIDTH-1:0]   master_a_size,
  input  logic [NUM_MASTERS*SRC_WIDTH-1:0]    master_a_source,
  input  logic [NUM_MASTERS*ADDR_WIDTH-1:0]   master_a_address,
  input  logic [NUM_MASTERS*MASK_WIDTH-1:0]   master_a_mask,
  input  logic [NUM_MASTERS*DATA_WIDTH-1:0]   master_a_data,
  
  // Channel D (Response) to masters.
  output logic [NUM_MASTERS-1:0] master_d_valid,
  input  logic [NUM_MASTERS-1:0] master_d_ready,
  output logic [NUM_MASTERS*OPCODE_WIDTH-1:0] master_d_opcode,
  output logic [NUM_MASTERS*PARAM_WIDTH-1:0]  master_d_param,
  output logic [NUM_MASTERS*SIZE_WIDTH-1:0]   master_d_size,
  output logic [NUM_MASTERS*SRC_WIDTH-1:0]    master_d_source,
  output logic [NUM_MASTERS*SINK_WIDTH-1:0]   master_d_sink,
  output logic [NUM_MASTERS*DATA_WIDTH-1:0]   master_d_data,
  output logic [NUM_MASTERS-1:0] master_d_error,
  
  // --------------------- Slave Socket Interface ---------------------
  // These ports are left open for testbench stimuli to simulate the slave (e.g. GPIO).
  
  // Channel A (Request) toward slave.
  output logic slave_a_valid,
  input  logic slave_a_ready,
  output logic [OPCODE_WIDTH-1:0] slave_a_opcode,
  output logic [PARAM_WIDTH-1:0]  slave_a_param,
  output logic [SIZE_WIDTH-1:0]   slave_a_size,
  output logic [SRC_WIDTH-1:0]    slave_a_source,
  output logic [ADDR_WIDTH-1:0]   slave_a_address,
  output logic [MASK_WIDTH-1:0]   slave_a_mask,
  output logic [DATA_WIDTH-1:0]   slave_a_data,
  
  // Channel D (Response) from slave.
  input  logic slave_d_valid,
  output logic slave_d_ready,
  input  logic [OPCODE_WIDTH-1:0] slave_d_opcode,
  input  logic [PARAM_WIDTH-1:0]  slave_d_param,
  input  logic [SIZE_WIDTH-1:0]   slave_d_size,
  input  logic [SRC_WIDTH-1:0]    slave_d_source,
  input  logic [SINK_WIDTH-1:0]   slave_d_sink,
  input  logic [DATA_WIDTH-1:0]   slave_d_data,
  input  logic slave_d_error
);

  // --------------------- Internal Signal Declarations ---------------------
  
  // Signals between the master sockets and xbar_main (100 MHz domain).
  logic xbar_a_valid, xbar_a_ready;
  logic [OPCODE_WIDTH-1:0] xbar_a_opcode;
  logic [PARAM_WIDTH-1:0]  xbar_a_param;
  logic [SIZE_WIDTH-1:0]   xbar_a_size;
  logic [SRC_WIDTH-1:0]    xbar_a_source;
  logic [ADDR_WIDTH-1:0]   xbar_a_address;
  logic [MASK_WIDTH-1:0]   xbar_a_mask;
  logic [DATA_WIDTH-1:0]   xbar_a_data;
  
  logic xbar_d_valid, xbar_d_ready;
  logic [OPCODE_WIDTH-1:0] xbar_d_opcode;
  logic [PARAM_WIDTH-1:0]  xbar_d_param;
  logic [SIZE_WIDTH-1:0]   xbar_d_size;
  logic [SRC_WIDTH-1:0]    xbar_d_source;
  logic [SINK_WIDTH-1:0]   xbar_d_sink;
  logic [DATA_WIDTH-1:0]   xbar_d_data;
  logic xbar_d_error;
  
  // Signals between the CDC adapter and xbar_peri (24 MHz domain).
  logic cdc_a_valid, cdc_a_ready;
  logic [OPCODE_WIDTH-1:0] cdc_a_opcode;
  logic [PARAM_WIDTH-1:0]  cdc_a_param;
  logic [SIZE_WIDTH-1:0]   cdc_a_size;
  logic [SRC_WIDTH-1:0]    cdc_a_source;
  logic [ADDR_WIDTH-1:0]   cdc_a_address;
  logic [MASK_WIDTH-1:0]   cdc_a_mask;
  logic [DATA_WIDTH-1:0]   cdc_a_data;
  
  logic cdc_d_valid, cdc_d_ready;
  logic [OPCODE_WIDTH-1:0] cdc_d_opcode;
  logic [PARAM_WIDTH-1:0]  cdc_d_param;
  logic [SIZE_WIDTH-1:0]   cdc_d_size;
  logic [SRC_WIDTH-1:0]    cdc_d_source;
  logic [SINK_WIDTH-1:0]   cdc_d_sink;
  logic [DATA_WIDTH-1:0]   cdc_d_data;
  logic cdc_d_error;
  
  // --------------------- Module Instantiations ---------------------
  
  // xbar_main (100 MHz domain)
  xbar_main #(
    .NUM_MASTERS(NUM_MASTERS)
  ) u_xbar_main (
    .clk(clk_100),
    .reset(reset),
    // Master interface connections (from testbench stimuli)
    .a_valid(master_a_valid),
    .a_ready(master_a_ready),
    .a_opcode(master_a_opcode),
    .a_param(master_a_param),
    .a_size(master_a_size),
    .a_source(master_a_source),
    .a_address(master_a_address),
    .a_mask(master_a_mask),
    .a_data(master_a_data),
    .d_valid(master_d_valid),
    .d_ready(master_d_ready),
    .d_opcode(master_d_opcode),
    .d_param(master_d_param),
    .d_size(master_d_size),
    .d_source(master_d_source),
    .d_sink(master_d_sink),
    .d_data(master_d_data),
    .d_error(master_d_error),
    // Output to CDC adapter:
    .a_valid_out(xbar_a_valid),
    .a_ready_out(xbar_a_ready),
    .a_opcode_out(xbar_a_opcode),
    .a_param_out(xbar_a_param),
    .a_size_out(xbar_a_size),
    .a_source_out(xbar_a_source),
    .a_address_out(xbar_a_address),
    .a_mask_out(xbar_a_mask),
    .a_data_out(xbar_a_data),
    .d_valid_in(xbar_d_valid),
    .d_ready_in(xbar_d_ready),
    .d_opcode_in(xbar_d_opcode),
    .d_param_in(xbar_d_param),
    .d_size_in(xbar_d_size),
    .d_source_in(xbar_d_source),
    .d_sink_in(xbar_d_sink),
    .d_data_in(xbar_d_data),
    .d_error_in(xbar_d_error)
  );
  
  // CDC adapter bridges 100 MHz and 24 MHz domains.
  tilelink_cdc_adapter #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
    .MASK_WIDTH(MASK_WIDTH),
    .SIZE_WIDTH(SIZE_WIDTH),
    .SRC_WIDTH(SRC_WIDTH),
    .SINK_WIDTH(SINK_WIDTH),
    .OPCODE_WIDTH(OPCODE_WIDTH),
    .PARAM_WIDTH(PARAM_WIDTH),
    .FIFO_DEPTH(FIFO_DEPTH)
  ) u_cdc_adapter (
    // 100 MHz side (input from xbar_main)
    .clk_in(clk_100),
    .reset_in(reset),
    // 24 MHz side (output toward xbar_peri)
    .clk_out(clk_24),
    .reset_out(reset),
    .a_valid_in(xbar_a_valid),
    .a_ready_in(xbar_a_ready),
    .a_opcode_in(xbar_a_opcode),
    .a_param_in(xbar_a_param),
    .a_size_in(xbar_a_size),
    .a_source_in(xbar_a_source),
    .a_address_in(xbar_a_address),
    .a_mask_in(xbar_a_mask),
    .a_data_in(xbar_a_data),
    .a_valid_out(cdc_a_valid),
    .a_ready_out(cdc_a_ready),
    .a_opcode_out(cdc_a_opcode),
    .a_param_out(cdc_a_param),
    .a_size_out(cdc_a_size),
    .a_source_out(cdc_a_source),
    .a_address_out(cdc_a_address),
    .a_mask_out(cdc_a_mask),
    .a_data_out(cdc_a_data),
    // 24 MHz side (response path from slave through xbar_peri)
    .d_valid_in(cdc_d_valid),
    .d_ready_in(cdc_d_ready),
    .d_opcode_in(cdc_d_opcode),
    .d_param_in(cdc_d_param),
    .d_size_in(cdc_d_size),
    .d_source_in(cdc_d_source),
    .d_sink_in(cdc_d_sink),
    .d_data_in(cdc_d_data),
    .d_error_in(cdc_d_error),
    // Outputs to xbar_main domain (for master responses)
    .d_valid_out(xbar_d_valid),
    .d_ready_out(xbar_d_ready),
    .d_opcode_out(xbar_d_opcode),
    .d_param_out(xbar_d_param),
    .d_size_out(xbar_d_size),
    .d_source_out(xbar_d_source),
    .d_sink_out(xbar_d_sink),
    .d_data_out(xbar_d_data),
    .d_error_out(xbar_d_error)
  );
  
  // xbar_peri (24 MHz domain)
  xbar_peri #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
    .MASK_WIDTH(MASK_WIDTH),
    .SIZE_WIDTH(SIZE_WIDTH),
    .SRC_WIDTH(SRC_WIDTH),
    .SINK_WIDTH(SINK_WIDTH),
    .OPCODE_WIDTH(OPCODE_WIDTH),
    .PARAM_WIDTH(PARAM_WIDTH)
  ) u_xbar_peri (
    .clk(clk_24),
    .reset(reset),
    // Inputs from CDC adapter (24 MHz domain)
    .a_valid(cdc_a_valid),
    .a_ready(cdc_a_ready),
    .a_opcode(cdc_a_opcode),
    .a_param(cdc_a_param),
    .a_size(cdc_a_size),
    .a_source(cdc_a_source),
    .a_address(cdc_a_address),
    .a_mask(cdc_a_mask),
    .a_data(cdc_a_data),
    .d_valid(cdc_d_valid),
    .d_ready(cdc_d_ready),
    .d_opcode(cdc_d_opcode),
    .d_param(cdc_d_param),
    .d_size(cdc_d_size),
    .d_source(cdc_d_source),
    .d_sink(cdc_d_sink),
    .d_data(cdc_d_data),
    .d_error(cdc_d_error),
    // Slave socket interface (exposed to testbench)
    .a_valid_out(slave_a_valid),
    .a_ready_out(slave_a_ready),
    .a_opcode_out(slave_a_opcode),
    .a_param_out(slave_a_param),
    .a_size_out(slave_a_size),
    .a_source_out(slave_a_source),
    .a_address_out(slave_a_address),
    .a_mask_out(slave_a_mask),
    .a_data_out(slave_a_data),
    .d_valid_in(slave_d_valid),
    .d_ready_in(slave_d_ready),
    .d_opcode_in(slave_d_opcode),
    .d_param_in(slave_d_param),
    .d_size_in(slave_d_size),
    .d_source_in(slave_d_source),
    .d_sink_in(slave_d_sink),
    .d_data_in(slave_d_data),
    .d_error_in(slave_d_error)
  );
  
endmodule
