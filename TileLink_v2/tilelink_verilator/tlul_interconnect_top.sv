// tlul_interconnect_top.sv - Top-level interconnect for TL-UL  
// Fixed 3 masters (CPU, acc0, acc1) and 1 slave (GPIO); TL-UL (Uncached Lightweight) only.

module tlul_interconnect_top #(
  parameter SOURCE_ID_WIDTH  = 2,                // Width of Source ID field
  parameter [31:0] SLAVE_BASE  = 32'h0000_0000,  // Base address for the single slave
  parameter [31:0] SLAVE_MASK  = 32'hFFFF_F000,  // Address mask for the single slave (4KB region)
  parameter ADDR_WIDTH   = 32,
  parameter DATA_WIDTH   = 32,
  parameter MASK_WIDTH   = DATA_WIDTH/8,         // e.g. 4-bit mask for 32-bit data 
  parameter SIZE_WIDTH   = 3,                    // TL-UL size field (3 bits)
  parameter SRC_WIDTH    = SOURCE_ID_WIDTH,      // Source ID width (fixed to 2 for 3 masters)
  parameter SINK_WIDTH   = 1,
  parameter OPCODE_WIDTH = 3,                    // TL-UL opcode width
  parameter PARAM_WIDTH  = 3,
  parameter FIFO_DEPTH   = 8
)(
  // Clocks and reset
  input  logic clk_100,    // 100 MHz domain (masters & xbar_main)
  input  logic clk_24,     // 24 MHz domain (xbar_peri & slave)
  input  logic reset,

  // --------------------- Master Socket Interface ---------------------
  // Master -> Interconnect (TileLink Channel A request)
  input  logic [2:0]               master_a_valid,
  output logic [2:0]               master_a_ready,
  input  logic [3*OPCODE_WIDTH-1:0]  master_a_opcode,
  input  logic [3*PARAM_WIDTH-1:0]   master_a_param,
  input  logic [3*SIZE_WIDTH-1:0]    master_a_size,
  input  logic [3*SRC_WIDTH-1:0]     master_a_source,
  input  logic [3*ADDR_WIDTH-1:0]    master_a_address,
  input  logic [3*MASK_WIDTH-1:0]    master_a_mask,
  input  logic [3*DATA_WIDTH-1:0]    master_a_data,

  // Interconnect -> Master (TileLink Channel D response)
  output logic [2:0]               master_d_valid,
  input  logic [2:0]               master_d_ready,
  output logic [3*OPCODE_WIDTH-1:0]  master_d_opcode,
  output logic [3*PARAM_WIDTH-1:0]   master_d_param,
  output logic [3*SIZE_WIDTH-1:0]    master_d_size,
  output logic [3*SRC_WIDTH-1:0]     master_d_source,
  output logic [3*SINK_WIDTH-1:0]    master_d_sink,
  output logic [3*DATA_WIDTH-1:0]    master_d_data,
  output logic [2:0]               master_d_error,

  // --------------------- Slave Socket Interface ---------------------
  // Interconnect -> Slave (Channel A request)
  output logic               slave_a_valid,
  input  logic               slave_a_ready,
  output logic [OPCODE_WIDTH-1:0] slave_a_opcode,
  output logic [PARAM_WIDTH-1:0]  slave_a_param,
  output logic [SIZE_WIDTH-1:0]   slave_a_size,
  output logic [SRC_WIDTH-1:0]    slave_a_source,
  output logic [ADDR_WIDTH-1:0]   slave_a_address,
  output logic [MASK_WIDTH-1:0]   slave_a_mask,
  output logic [DATA_WIDTH-1:0]   slave_a_data,

  // Slave -> Interconnect (Channel D response)
  input  logic               slave_d_valid,
  output logic               slave_d_ready,
  input  logic [OPCODE_WIDTH-1:0] slave_d_opcode,
  input  logic [PARAM_WIDTH-1:0]  slave_d_param,
  input  logic [SIZE_WIDTH-1:0]   slave_d_size,
  input  logic [SRC_WIDTH-1:0]    slave_d_source,
  input  logic [SINK_WIDTH-1:0]   slave_d_sink,
  input  logic [DATA_WIDTH-1:0]   slave_d_data,
  input  logic               slave_d_error
);

  // --------------------- Internal Signal Declarations ---------------------
  // Signals between xbar_main (100 MHz) and CDC adapter
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
  logic                    xbar_d_error;

  // Signals between CDC adapter and xbar_peri (24 MHz)
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
  logic                    cdc_d_error;

  // --------------------- Module Instantiations ---------------------
  // 100 MHz crossbar (arbiter) for master requests
  xbar_main #(
    .ADDR_WIDTH   (ADDR_WIDTH),
    .DATA_WIDTH   (DATA_WIDTH),
    .MASK_WIDTH   (MASK_WIDTH),
    .SIZE_WIDTH   (SIZE_WIDTH),
    .SRC_WIDTH    (SRC_WIDTH),
    .SINK_WIDTH   (SINK_WIDTH),
    .OPCODE_WIDTH (OPCODE_WIDTH),
    .PARAM_WIDTH  (PARAM_WIDTH)
  ) u_xbar_main (
    .clk         (clk_100),
    .reset       (reset),
    // Master-side inputs (from masters)
    .a_valid     (master_a_valid),
    .a_ready     (master_a_ready),
    .a_opcode    (master_a_opcode),
    .a_param     (master_a_param),
    .a_size      (master_a_size),
    .a_source    (master_a_source),
    .a_address   (master_a_address),
    .a_mask      (master_a_mask),
    .a_data      (master_a_data),
    .d_valid     (master_d_valid),
    .d_ready     (master_d_ready),
    .d_opcode    (master_d_opcode),
    .d_param     (master_d_param),
    .d_size      (master_d_size),
    .d_source    (master_d_source),
    .d_sink      (master_d_sink),
    .d_data      (master_d_data),
    .d_error     (master_d_error),
    // Outputs to CDC adapter (100 MHz domain)
    .a_valid_out (xbar_a_valid),
    .a_ready_out (xbar_a_ready),
    .a_opcode_out(xbar_a_opcode),
    .a_param_out (xbar_a_param),
    .a_size_out  (xbar_a_size),
    .a_source_out(xbar_a_source),
    .a_address_out(xbar_a_address),
    .a_mask_out  (xbar_a_mask),
    .a_data_out  (xbar_a_data),
    .d_valid_in  (xbar_d_valid),
    .d_ready_in  (xbar_d_ready),
    .d_opcode_in (xbar_d_opcode),
    .d_param_in  (xbar_d_param),
    .d_size_in   (xbar_d_size),
    .d_source_in (xbar_d_source),
    .d_sink_in   (xbar_d_sink),
    .d_data_in   (xbar_d_data),
    .d_error_in  (xbar_d_error)
  );

  // CDC adapter bridging 100 MHz (xbar_main) to 24 MHz (xbar_peri)
  tilelink_cdc_adapter #(
    .ADDR_WIDTH   (ADDR_WIDTH),
    .DATA_WIDTH   (DATA_WIDTH),
    .MASK_WIDTH   (MASK_WIDTH),
    .SIZE_WIDTH   (SIZE_WIDTH),
    .SRC_WIDTH    (SRC_WIDTH),
    .SINK_WIDTH   (SINK_WIDTH),
    .OPCODE_WIDTH (OPCODE_WIDTH),
    .PARAM_WIDTH  (PARAM_WIDTH),
    .FIFO_DEPTH   (FIFO_DEPTH)
  ) u_cdc_adapter (
    // Channel A (100 MHz domain input from xbar_main)
    .clk_in       (clk_100),
    .reset_in     (reset),
    .a_valid_in   (xbar_a_valid),
    .a_ready_in   (xbar_a_ready),
    .a_opcode_in  (xbar_a_opcode),
    .a_param_in   (xbar_a_param),
    .a_size_in    (xbar_a_size),
    .a_source_in  (xbar_a_source),
    .a_address_in (xbar_a_address),
    .a_mask_in    (xbar_a_mask),
    .a_data_in    (xbar_a_data),
    // Channel A (24 MHz domain output toward xbar_peri)
    .clk_out      (clk_24),
    .reset_out    (reset),
    .a_valid_out  (cdc_a_valid),
    .a_ready_out  (cdc_a_ready),
    .a_opcode_out (cdc_a_opcode),
    .a_param_out  (cdc_a_param),
    .a_size_out   (cdc_a_size),
    .a_source_out (cdc_a_source),
    .a_address_out(cdc_a_address),
    .a_mask_out   (cdc_a_mask),
    .a_data_out   (cdc_a_data),
    // Channel D (24 MHz domain input from xbar_peri / slave)
    .d_valid_in   (cdc_d_valid),
    .d_ready_in   (cdc_d_ready),
    .d_opcode_in  (cdc_d_opcode),
    .d_param_in   (cdc_d_param),
    .d_size_in    (cdc_d_size),
    .d_source_in  (cdc_d_source),
    .d_sink_in    (cdc_d_sink),
    .d_data_in    (cdc_d_data),
    .d_error_in   (cdc_d_error),
    // Channel D (100 MHz domain output to xbar_main / masters)
    .d_valid_out  (xbar_d_valid),
    .d_ready_out  (xbar_d_ready),
    .d_opcode_out (xbar_d_opcode),
    .d_param_out  (xbar_d_param),
    .d_size_out   (xbar_d_size),
    .d_source_out (xbar_d_source),
    .d_sink_out   (xbar_d_sink),
    .d_data_out   (xbar_d_data),
    .d_error_out  (xbar_d_error)
  );

  // 24 MHz crossbar (peripheral side) – currently just pass-through for a single slave
  xbar_peri #(
    .ADDR_WIDTH   (ADDR_WIDTH),
    .DATA_WIDTH   (DATA_WIDTH),
    .MASK_WIDTH   (MASK_WIDTH),
    .SIZE_WIDTH   (SIZE_WIDTH),
    .SRC_WIDTH    (SRC_WIDTH),
    .SINK_WIDTH   (SINK_WIDTH),
    .OPCODE_WIDTH (OPCODE_WIDTH),
    .PARAM_WIDTH  (PARAM_WIDTH)
    // Note: Could extend to support multiple slaves by implementing address decode using SLAVE_BASE/MASK.
  ) u_xbar_peri (
    .clk          (clk_24),
    .reset        (reset),
    // Inputs from CDC adapter (24 MHz domain)
    .a_valid      (cdc_a_valid),
    .a_ready      (cdc_a_ready),
    .a_opcode     (cdc_a_opcode),
    .a_param      (cdc_a_param),
    .a_size       (cdc_a_size),
    .a_source     (cdc_a_source),
    .a_address    (cdc_a_address),
    .a_mask       (cdc_a_mask),
    .a_data       (cdc_a_data),
    .d_valid      (cdc_d_valid),
    .d_ready      (cdc_d_ready),
    .d_opcode     (cdc_d_opcode),
    .d_param      (cdc_d_param),
    .d_size       (cdc_d_size),
    .d_source     (cdc_d_source),
    .d_sink       (cdc_d_sink),
    .d_data       (cdc_d_data),
    .d_error      (cdc_d_error),
    // Slave-side signals (exposed to testbench or slave device)
    .a_valid_out  (slave_a_valid),
    .a_ready_out  (slave_a_ready),
    .a_opcode_out (slave_a_opcode),
    .a_param_out  (slave_a_param),
    .a_size_out   (slave_a_size),
    .a_source_out (slave_a_source),
    .a_address_out(slave_a_address),
    .a_mask_out   (slave_a_mask),
    .a_data_out   (slave_a_data),
    .d_valid_in   (slave_d_valid),
    .d_ready_in   (slave_d_ready),
    .d_opcode_in  (slave_d_opcode),
    .d_param_in   (slave_d_param),
    .d_size_in    (slave_d_size),
    .d_source_in  (slave_d_source),
    .d_sink_in    (slave_d_sink),
    .d_data_in    (slave_d_data),
    .d_error_in   (slave_d_error)
  );

endmodule
