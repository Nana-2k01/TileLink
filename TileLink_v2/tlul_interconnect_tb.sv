`timescale 1ns / 1ps

module tlul_interconnect_tb;

  // Clock and reset signals
  logic clk_100, clk_24, reset;

  // Generate 100 MHz clock (10 ns period)
  initial begin
    clk_100 = 0;
    forever #5 clk_100 = ~clk_100;
  end

  // Generate 24 MHz clock (~41.67 ns period)
  initial begin
    clk_24 = 0;
    forever #21 clk_24 = ~clk_24;
  end

  // Reset generation
  initial begin
    reset = 1;
    #20 reset = 0;
  end

  // Parameters (match DUT)
  localparam NUM_MASTERS  = 3;
  localparam OPCODE_WIDTH = 3;
  localparam PARAM_WIDTH  = 3;
  localparam SIZE_WIDTH   = 3;
  localparam SRC_WIDTH    = 2;
  localparam SINK_WIDTH   = 1;
  localparam ADDR_WIDTH   = 32;
  localparam DATA_WIDTH   = 32;
  localparam MASK_WIDTH   = DATA_WIDTH / 8;  // 4

  // Master interface signals (vectors for A and D channels)
  logic [NUM_MASTERS-1:0]               master_a_valid;
  logic [NUM_MASTERS-1:0]               master_a_ready;
  logic [NUM_MASTERS*OPCODE_WIDTH-1:0]  master_a_opcode;
  logic [NUM_MASTERS*PARAM_WIDTH-1:0]   master_a_param;
  logic [NUM_MASTERS*SIZE_WIDTH-1:0]    master_a_size;
  logic [NUM_MASTERS*SRC_WIDTH-1:0]     master_a_source;
  logic [NUM_MASTERS*ADDR_WIDTH-1:0]    master_a_address;
  logic [NUM_MASTERS*MASK_WIDTH-1:0]    master_a_mask;
  logic [NUM_MASTERS*DATA_WIDTH-1:0]    master_a_data;

  logic [NUM_MASTERS-1:0]               master_d_valid;
  logic [NUM_MASTERS-1:0]               master_d_ready;
  logic [NUM_MASTERS*OPCODE_WIDTH-1:0]  master_d_opcode;
  logic [NUM_MASTERS*PARAM_WIDTH-1:0]   master_d_param;
  logic [NUM_MASTERS*SIZE_WIDTH-1:0]    master_d_size;
  logic [NUM_MASTERS*SRC_WIDTH-1:0]     master_d_source;
  logic [NUM_MASTERS*SINK_WIDTH-1:0]    master_d_sink;
  logic [NUM_MASTERS*DATA_WIDTH-1:0]    master_d_data;
  logic [NUM_MASTERS-1:0]               master_d_error;

  // Slave interface signals (simulate a peripheral)
  logic slave_a_valid;
  logic slave_a_ready;
  logic [OPCODE_WIDTH-1:0] slave_a_opcode;
  logic [PARAM_WIDTH-1:0]  slave_a_param;
  logic [SIZE_WIDTH-1:0]   slave_a_size;
  logic [SRC_WIDTH-1:0]    slave_a_source;
  logic [ADDR_WIDTH-1:0]   slave_a_address;
  logic [MASK_WIDTH-1:0]   slave_a_mask;
  logic [DATA_WIDTH-1:0]   slave_a_data;

  logic slave_d_valid;
  logic slave_d_ready;
  logic [OPCODE_WIDTH-1:0] slave_d_opcode;
  logic [PARAM_WIDTH-1:0]  slave_d_param;
  logic [SIZE_WIDTH-1:0]   slave_d_size;
  logic [SRC_WIDTH-1:0]    slave_d_source;
  logic [SINK_WIDTH-1:0]   slave_d_sink;
  logic [DATA_WIDTH-1:0]   slave_d_data;
  logic slave_d_error;

  // Instantiate the Device Under Test (DUT)
  tlul_interconnect_top #(
    // (Using default parameters as defined in the DUT)
  ) u_top (
    .clk_100       (clk_100),
    .clk_24        (clk_24),
    .reset         (reset),
    .master_a_valid(master_a_valid),
    .master_a_ready(master_a_ready),
    .master_a_opcode(master_a_opcode),
    .master_a_param(master_a_param),
    .master_a_size (master_a_size),
    .master_a_source(master_a_source),
    .master_a_address(master_a_address),
    .master_a_mask (master_a_mask),
    .master_a_data (master_a_data),
    .master_d_valid(master_d_valid),
    .master_d_ready(master_d_ready),
    .master_d_opcode(master_d_opcode),
    .master_d_param(master_d_param),
    .master_d_size (master_d_size),
    .master_d_source(master_d_source),
    .master_d_sink (master_d_sink),
    .master_d_data (master_d_data),
    .master_d_error(master_d_error),
    .slave_a_valid (slave_a_valid),
    .slave_a_ready (slave_a_ready),
    .slave_a_opcode(slave_a_opcode),
    .slave_a_param (slave_a_param),
    .slave_a_size  (slave_a_size),
    .slave_a_source(slave_a_source),
    .slave_a_address(slave_a_address),
    .slave_a_mask  (slave_a_mask),
    .slave_a_data  (slave_a_data),
    .slave_d_valid (slave_d_valid),
    .slave_d_ready (slave_d_ready),
    .slave_d_opcode(slave_d_opcode),
    .slave_d_param (slave_d_param),
    .slave_d_size  (slave_d_size),
    .slave_d_source(slave_d_source),
    .slave_d_sink  (slave_d_sink),
    .slave_d_data  (slave_d_data),
    .slave_d_error (slave_d_error)
  );

  // Tasks to drive TileLink transactions (Put and Get)
  task drive_put(input int master_id, input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data_val);
    begin
      master_a_valid[master_id] <= 1'b1;
      master_a_address[master_id*ADDR_WIDTH +: ADDR_WIDTH] <= addr;
      master_a_data[master_id*DATA_WIDTH +: DATA_WIDTH]   <= data_val;
      master_a_opcode[master_id*OPCODE_WIDTH +: OPCODE_WIDTH] <= 3'd0;  // PutFullData
      master_a_param[master_id*PARAM_WIDTH +: PARAM_WIDTH]   <= 3'd0;
      master_a_size[master_id*SIZE_WIDTH +: SIZE_WIDTH]     <= 3'd2;    // 4-byte access
      master_a_mask[master_id*MASK_WIDTH +: MASK_WIDTH]     <= {MASK_WIDTH{1'b1}};
      master_a_source[master_id*SRC_WIDTH +: SRC_WIDTH]     <= master_id;
      wait(master_a_ready[master_id]);  // wait until interconnect is ready
      @(posedge clk_100);
      master_a_valid[master_id] <= 1'b0;
    end
  endtask

  task drive_get(input int master_id, input logic [ADDR_WIDTH-1:0] addr);
    begin
      master_a_valid[master_id] <= 1'b1;
      master_a_address[master_id*ADDR_WIDTH +: ADDR_WIDTH] <= addr;
      master_a_opcode[master_id*OPCODE_WIDTH +: OPCODE_WIDTH] <= 3'd4;  // Get
      master_a_param[master_id*PARAM_WIDTH +: PARAM_WIDTH]   <= 3'd0;
      master_a_size[master_id*SIZE_WIDTH +: SIZE_WIDTH]     <= 3'd2;
      master_a_mask[master_id*MASK_WIDTH +: MASK_WIDTH]     <= {MASK_WIDTH{1'b1}};
      master_a_source[master_id*SRC_WIDTH +: SRC_WIDTH]     <= master_id;
      master_a_data[master_id*DATA_WIDTH +: DATA_WIDTH]     <= {DATA_WIDTH{1'b0}}; // no write data
      wait(master_a_ready[master_id]);
      @(posedge clk_100);
      master_a_valid[master_id] <= 1'b0;
    end
  endtask

  // Test sequence
  initial begin
    // Initialize all master outputs and slave inputs
    foreach (master_a_valid[i]) master_a_valid[i] = 1'b0;
    master_d_ready = {NUM_MASTERS{1'b1}};        // Masters always ready to accept responses
    slave_a_ready  = 1'b0;                      // Slave not ready initially
    slave_d_valid  = 1'b0;
    master_a_opcode = '0;
    master_a_param  = '0;
    master_a_size   = {NUM_MASTERS{3'd2}};      // default size = 4 bytes for all
    master_a_mask   = {NUM_MASTERS{ {MASK_WIDTH{1'b1}} }}; // default all-ones mask
    master_a_data   = '0;
    for (int m = 0; m < NUM_MASTERS; m++)
      master_a_source[m*SRC_WIDTH +: SRC_WIDTH] = m;

    @(negedge reset);
    #30;

    // Issue a mix of Put and Get requests from different masters
    fork
      drive_put(0, 32'h0000_1000, 32'hA5A5_A5A5);     // Master 0 writes 0xA5A5_A5A5 to 0x1000
      #20 drive_get(1, 32'h0000_2000);                // 20 ns: Master 1 reads from 0x2000
      #40 drive_put(2, 32'h0000_3000, 32'h5A5A_5A5A); // 40 ns: Master 2 writes to 0x3000
      #50 drive_get(0, 32'h0000_4000);                // 50 ns: Master 0 issues another read
      #50 drive_put(1, 32'h0000_5000, 32'h1111_2222); // 50 ns: Master 1 writes to 0x5000
      #50 drive_get(2, 32'h0000_6000);                // 50 ns: Master 2 reads from 0x6000
    join

    // After issuing all requests, allow the slave to start accepting them
    slave_a_ready = 1'b1;

    #100000 $finish;
  end

  // (Optional) A simple slave model could be added here to generate slave_d_valid and responses.
  // In this test, we focus on the interconnect forwarding, so no actual slave responses are generated.

endmodule
