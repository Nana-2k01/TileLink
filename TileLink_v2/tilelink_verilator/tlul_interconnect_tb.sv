`timescale 1ns/1ps

// Parameter Declarations
parameter DATA_WIDTH   = 32;
parameter ADDR_WIDTH   = 32;
parameter MASK_WIDTH   = DATA_WIDTH/8;
parameter SIZE_WIDTH   = 3;
parameter SRC_WIDTH    = 2;
parameter SINK_WIDTH   = 1;
parameter OPCODE_WIDTH = 3;
parameter PARAM_WIDTH  = 3;
parameter FIFO_DEPTH   = 8;

module tlul_interconnect_tb(
  //-------------------------------------------------------------------------
  // Testbench-Driven Signals (appear as if they are driven by hardware)
  //-------------------------------------------------------------------------
  // Clocks and reset
  output reg                 clk_100,
  output reg                 clk_24,
  output reg                 reset,
  
  // Master-side Channel A signals (stimulus outputs)
  output reg [2:0]           master_a_valid,
  output reg [3*OPCODE_WIDTH-1:0] master_a_opcode,
  output reg [3*PARAM_WIDTH-1:0]  master_a_param,
  output reg [3*SIZE_WIDTH-1:0]   master_a_size,
  output reg [3*SRC_WIDTH-1:0]    master_a_source,
  output reg [3*ADDR_WIDTH-1:0]   master_a_address,
  output reg [3*MASK_WIDTH-1:0]   master_a_mask,
  output reg [3*DATA_WIDTH-1:0]   master_a_data,
  
  // Master-side Channel D ready (stimulus output)
  output reg [2:0]           master_d_ready,
  
  // Slave-D channel signals (stimulus outputs; these emulate a slave model driving responses)
  output reg                 slave_d_ready,
  output reg                 slave_d_valid,
  output reg [OPCODE_WIDTH-1:0] slave_d_opcode,
  output reg [PARAM_WIDTH-1:0]  slave_d_param,
  output reg [SIZE_WIDTH-1:0]   slave_d_size,
  output reg [SRC_WIDTH-1:0]    slave_d_source,
  output reg [SINK_WIDTH-1:0]   slave_d_sink,
  output reg [DATA_WIDTH-1:0]   slave_d_data,
  output reg                 slave_d_error
);

  //-------------------------------------------------------------------------
  // Internal Wires for DUT-Driven Signals
  //-------------------------------------------------------------------------
  // Slave-A channel (driven by the DUT)
  wire                slave_a_valid;
  wire [OPCODE_WIDTH-1:0] slave_a_opcode;
  wire [PARAM_WIDTH-1:0]  slave_a_param;
  wire [SIZE_WIDTH-1:0]   slave_a_size;
  wire [SRC_WIDTH-1:0]    slave_a_source;
  wire [3*ADDR_WIDTH-1:0] slave_a_address;
  wire [3*MASK_WIDTH-1:0] slave_a_mask;
  wire [3*DATA_WIDTH-1:0] slave_a_data;
  
  // Master-D channel (driven by the DUT)
  wire [2:0]                master_a_ready;
  wire [2:0]                master_d_valid;
  wire [3*OPCODE_WIDTH-1:0] master_d_opcode;
  wire [3*PARAM_WIDTH-1:0]  master_d_param;
  wire [3*SIZE_WIDTH-1:0]   master_d_size;
  wire [3*SRC_WIDTH-1:0]    master_d_source;
  wire [3*SINK_WIDTH-1:0]   master_d_sink;
  wire [3*DATA_WIDTH-1:0]   master_d_data;
  wire [2:0]                master_d_error;
  
  //-------------------------------------------------------------------------
  // Clock Generation
  //-------------------------------------------------------------------------
  initial begin
    clk_100 = 0;
    forever #5 clk_100 = ~clk_100;  // 100 MHz clock (period = 10 time units)
  end
  
  initial begin
    clk_24 = 0;
    forever #21 clk_24 = ~clk_24;   // 24 MHz clock (approximate period)
  end
  
  //-------------------------------------------------------------------------
  // Initial Setup and Master Stimulus
  //-------------------------------------------------------------------------
  integer master_id;
  integer m;
  
  initial begin
    // Initialize testbench-driven signals
    reset           = 1;
    master_a_valid  = 3'b0;
    master_a_opcode = 0;
    master_a_param  = 0;
    master_a_size   = 0;
    master_a_source = 0;
    master_a_address= 0;
    master_a_mask   = {3*MASK_WIDTH{1'b1}};
    master_a_data   = 0;
    master_d_ready  = 3'b111; // Stimulus: masters are always ready for responses

    // Initialize slave-D stimulus outputs (for our slave model)
    slave_d_ready   = 0; // Initially not ready
    slave_d_valid   = 0;
    slave_d_opcode  = 0;
    slave_d_param   = 0;
    slave_d_size    = 0;
    slave_d_source  = 0;
    slave_d_sink    = 0;
    slave_d_data    = 0;
    slave_d_error   = 0;
    
    // Deassert reset after 20 time units
    #20 reset = 0;
    
    //--- Begin Master Stimulus Sequence ---
    // Stimulus for Master 0: Issue a Get request
    master_id = 0;
    master_a_valid[master_id] = 1;
    master_a_opcode[master_id*OPCODE_WIDTH +: OPCODE_WIDTH] = 3'd4; // Get operation
    master_a_address[master_id*ADDR_WIDTH +: ADDR_WIDTH] = 32'h0000_1000;
    master_a_size[master_id*SIZE_WIDTH +: SIZE_WIDTH] = 3'd2; // 4-byte transfer
    master_a_data[master_id*DATA_WIDTH +: DATA_WIDTH] = 32'hDEAD_BEEF;
    wait(master_a_ready[master_id]);
    @(posedge clk_100);
    master_a_valid[master_id] = 0;
    
    // Stimulus for Master 1: Issue a PutFullData request
    master_id = 1;
    master_a_valid[master_id] = 1;
    master_a_opcode[master_id*OPCODE_WIDTH +: OPCODE_WIDTH] = 3'd0; // PutFullData
    master_a_address[master_id*ADDR_WIDTH +: ADDR_WIDTH] = 32'h0000_2000;
    master_a_size[master_id*SIZE_WIDTH +: SIZE_WIDTH] = 3'd2;
    master_a_data[master_id*DATA_WIDTH +: DATA_WIDTH] = 32'hCAFEBABE;
    wait(master_a_ready[master_id]);
    @(posedge clk_100);
    master_a_valid[master_id] = 0;
    
    // Stimulus for Master 2: Issue a PutPartialData request
    m = 2;
    master_a_valid[m] = 1;
    master_a_opcode[m*OPCODE_WIDTH +: OPCODE_WIDTH] = 3'd1; // PutPartialData
    master_a_address[m*ADDR_WIDTH +: ADDR_WIDTH] = 32'h0000_3000;
    master_a_size[m*SIZE_WIDTH +: SIZE_WIDTH] = 3'd2;
    master_a_data[m*DATA_WIDTH +: DATA_WIDTH] = 32'h12345678;
    wait(master_a_ready[m]);
    @(posedge clk_100);
    master_a_valid[m] = 0;
    
    // End simulation after a sufficient delay
    #100000 $finish;
  end
  
  //-------------------------------------------------------------------------
  // Slave Model to Generate Responses (driving slave-D outputs)
  //-------------------------------------------------------------------------
  // This block monitors the DUT-driven slave-A channel and, after a short delay,
  // drives the slave-D response signals to emulate a hardware slave.
  initial begin
    // Initialize slave-D outputs (already done above, but can be reiterated)
    slave_d_valid  = 0;
    slave_d_opcode = 0;
    slave_d_param  = 0;
    slave_d_size   = 0;
    slave_d_source = 0;
    slave_d_sink   = 0;
    slave_d_data   = 0;
    slave_d_error  = 0;
    
    // After 50 time units, indicate that the slave is ready to accept a response.
    #50;
    slave_d_ready = 1;
    
    forever begin
      @(posedge clk_100);
      if (slave_a_valid) begin
         // Wait until the transaction is complete
         @(negedge slave_a_valid);
         // Simulate response latency
         #10;
         slave_d_valid = 1;
         // For a Get operation, send a data response; for a Put, send an acknowledge.
         if (slave_a_opcode == 3'd4) begin
             slave_d_opcode = 3'd1; // Data response for Get
             slave_d_data   = 32'hDEAD_BEEF;
         end else begin
             slave_d_opcode = 3'd0; // Acknowledge for Put
             slave_d_data   = 32'h0;
         end
         slave_d_param  = slave_a_param;
         slave_d_size   = slave_a_size;
         slave_d_source = slave_a_source;
         slave_d_sink   = 0;
         slave_d_error  = 0;
         @(posedge clk_100);
         slave_d_valid = 0;
      end
    end
  end
  
  //-------------------------------------------------------------------------
  // DUT Instantiation
  //-------------------------------------------------------------------------
  tlul_interconnect_top #(
    .SOURCE_ID_WIDTH(SRC_WIDTH),
    .SLAVE_BASE(32'h0000_0000),
    .SLAVE_MASK(32'hFFFF_F000),
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
    .MASK_WIDTH(MASK_WIDTH),
    .SIZE_WIDTH(SIZE_WIDTH),
    .SRC_WIDTH(SRC_WIDTH),
    .SINK_WIDTH(SINK_WIDTH),
    .OPCODE_WIDTH(OPCODE_WIDTH),
    .PARAM_WIDTH(PARAM_WIDTH),
    .FIFO_DEPTH(FIFO_DEPTH)
  ) u_top (
    .clk_100(clk_100),
    .clk_24(clk_24),
    .reset(reset),
    // Master Socket Connections
    .master_a_valid(master_a_valid),
    .master_a_ready(master_a_ready),
    .master_a_opcode(master_a_opcode),
    .master_a_param(master_a_param),
    .master_a_size(master_a_size),
    .master_a_source(master_a_source),
    .master_a_address(master_a_address),
    .master_a_mask(master_a_mask),
    .master_a_data(master_a_data),
    .master_d_valid(master_d_valid),
    .master_d_ready(master_d_ready),
    .master_d_opcode(master_d_opcode),
    .master_d_param(master_d_param),
    .master_d_size(master_d_size),
    .master_d_source(master_d_source),
    .master_d_sink(master_d_sink),
    .master_d_data(master_d_data),
    .master_d_error(master_d_error),
    // Slave Socket Connections
    .slave_a_valid(slave_a_valid),
    .slave_a_ready(), // The DUT drives this; testbench does not drive slave_A ready.
    .slave_a_opcode(slave_a_opcode),
    .slave_a_param(slave_a_param),
    .slave_a_size(slave_a_size),
    .slave_a_source(slave_a_source),
    .slave_a_address(slave_a_address),
    .slave_a_mask(slave_a_mask),
    .slave_a_data(slave_a_data),
    // The slave-D channel is driven by our slave model
    .slave_d_ready(slave_d_ready),
    .slave_d_valid(slave_d_valid),
    .slave_d_opcode(slave_d_opcode),
    .slave_d_param(slave_d_param),
    .slave_d_size(slave_d_size),
    .slave_d_source(slave_d_source),
    .slave_d_sink(slave_d_sink),
    .slave_d_data(slave_d_data),
    .slave_d_error(slave_d_error)
  );
  
endmodule
