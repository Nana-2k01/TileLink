`timescale 1ns / 1ps

module tlul_interconnect_tb;

  // Clock signals
  logic clk_100, clk_24, reset;

  // Generate a 100 MHz clock (period = 10 ns)
  initial begin
    clk_100 = 0;
    forever #5 clk_100 = ~clk_100;
  end

  // Generate a 24 MHz clock (approx period = 42 ns)
  initial begin
    clk_24 = 0;
    forever #21 clk_24 = ~clk_24;
  end

  // Reset generation
  initial begin
    reset = 1;
    #20;
    reset = 0;
  end

  // Parameter definitions
  localparam NUM_MASTERS  = 3;
  localparam OPCODE_WIDTH = 3;
  localparam PARAM_WIDTH  = 3;
  localparam SIZE_WIDTH   = 3;
  localparam SRC_WIDTH    = 2;
  localparam SINK_WIDTH   = 1;
  localparam ADDR_WIDTH   = 32;
  localparam DATA_WIDTH   = 32;
  localparam MASK_WIDTH   = DATA_WIDTH/8;

  // ------------------ Master Socket Interface Signals ------------------
  logic [NUM_MASTERS-1:0] master_a_valid;
  logic [NUM_MASTERS-1:0] master_a_ready;
  logic [NUM_MASTERS*OPCODE_WIDTH-1:0] master_a_opcode;
  logic [NUM_MASTERS*PARAM_WIDTH-1:0]  master_a_param;
  logic [NUM_MASTERS*SIZE_WIDTH-1:0]   master_a_size;
  logic [NUM_MASTERS*SRC_WIDTH-1:0]    master_a_source;
  logic [NUM_MASTERS*ADDR_WIDTH-1:0]   master_a_address;
  logic [NUM_MASTERS*MASK_WIDTH-1:0]   master_a_mask;
  logic [NUM_MASTERS*DATA_WIDTH-1:0]   master_a_data;

  logic [NUM_MASTERS-1:0] master_d_valid;
  logic [NUM_MASTERS-1:0] master_d_ready;
  logic [NUM_MASTERS*OPCODE_WIDTH-1:0] master_d_opcode;
  logic [NUM_MASTERS*PARAM_WIDTH-1:0]  master_d_param;
  logic [NUM_MASTERS*SIZE_WIDTH-1:0]   master_d_size;
  logic [NUM_MASTERS*SRC_WIDTH-1:0]    master_d_source;
  logic [NUM_MASTERS*SINK_WIDTH-1:0]   master_d_sink;
  logic [NUM_MASTERS*DATA_WIDTH-1:0]   master_d_data;
  logic [NUM_MASTERS-1:0] master_d_error;

  // ------------------ Slave Socket Interface Signals ------------------
  logic slave_a_valid;
  logic [OPCODE_WIDTH-1:0] slave_a_opcode;
  logic [PARAM_WIDTH-1:0]  slave_a_param;
  logic [SIZE_WIDTH-1:0]   slave_a_size;
  logic [SRC_WIDTH-1:0]    slave_a_source;
  logic [ADDR_WIDTH-1:0]   slave_a_address;
  logic [MASK_WIDTH-1:0]   slave_a_mask;
  logic [DATA_WIDTH-1:0]   slave_a_data;
  logic slave_a_ready;

  // ------------------ Slave D Channel Signals ------------------
  logic slave_d_valid;
  logic [OPCODE_WIDTH-1:0] slave_d_opcode;
  logic [PARAM_WIDTH-1:0]  slave_d_param;
  logic [SIZE_WIDTH-1:0]   slave_d_size;
  logic [SRC_WIDTH-1:0]    slave_d_source;
  logic [SINK_WIDTH-1:0]   slave_d_sink;
  logic [DATA_WIDTH-1:0]   slave_d_data;
  logic slave_d_error;
  logic slave_d_ready;

  // ------------------ Instantiate DUT ------------------
  tlul_interconnect_top #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
    .MASK_WIDTH(MASK_WIDTH),
    .SIZE_WIDTH(SIZE_WIDTH),
    .SRC_WIDTH(SRC_WIDTH),
    .SINK_WIDTH(SINK_WIDTH),
    .OPCODE_WIDTH(OPCODE_WIDTH),
    .PARAM_WIDTH(PARAM_WIDTH),
    .NUM_MASTERS(NUM_MASTERS),
    .FIFO_DEPTH(8)
  ) u_top (
    .clk_100(clk_100),
    .clk_24(clk_24),
    .reset(reset),
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
    .slave_a_valid(slave_a_valid),
    .slave_a_ready(slave_a_ready),
    .slave_a_opcode(slave_a_opcode),
    .slave_a_param(slave_a_param),
    .slave_a_size(slave_a_size),
    .slave_a_source(slave_a_source),
    .slave_a_address(slave_a_address),
    .slave_a_mask(slave_a_mask),
    .slave_a_data(slave_a_data),
    .slave_d_valid(slave_d_valid),
    .slave_d_ready(slave_d_ready),
    .slave_d_opcode(slave_d_opcode),
    .slave_d_param(slave_d_param),
    .slave_d_size(slave_d_size),
    .slave_d_source(slave_d_source),
    .slave_d_sink(slave_d_sink),
    .slave_d_data(slave_d_data),
    .slave_d_error(slave_d_error)
  );

  // ------------------ Master Stimulus Tasks ------------------
  task drive_put(input integer master_id, input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data_val);
    integer idx;
    begin
      idx = master_id;
      master_a_valid[master_id] = 1'b1;
      master_a_opcode[idx*OPCODE_WIDTH +: OPCODE_WIDTH] = 3'd0;
      master_a_param[idx*PARAM_WIDTH +: PARAM_WIDTH]    = 3'd0;
      master_a_size[idx*SIZE_WIDTH +: SIZE_WIDTH]       = 3'd2;
      master_a_source[idx*SRC_WIDTH +: SRC_WIDTH]       = master_id;
      master_a_address[idx*ADDR_WIDTH +: ADDR_WIDTH]    = addr;
      master_a_mask[idx*MASK_WIDTH +: MASK_WIDTH]       = 4'b1111;
      master_a_data[idx*DATA_WIDTH +: DATA_WIDTH]       = data_val;
      
      wait(master_a_ready[master_id]);
      @(posedge clk_100);
      master_a_valid[master_id] = 1'b0;
      $display($time, " ns: Master %0d Put issued: Addr=0x%0h, Data=0x%0h", master_id, addr, data_val);
    end
  endtask

  task drive_get(input integer master_id, input logic [ADDR_WIDTH-1:0] addr);
    integer idx;
    begin
      idx = master_id;
      master_a_valid[master_id] = 1'b1;
      master_a_opcode[idx*OPCODE_WIDTH +: OPCODE_WIDTH] = 3'd4;
      master_a_param[idx*PARAM_WIDTH +: PARAM_WIDTH]    = 3'd0;
      master_a_size[idx*SIZE_WIDTH +: SIZE_WIDTH]       = 3'd2;
      master_a_source[idx*SRC_WIDTH +: SRC_WIDTH]       = master_id;
      master_a_address[idx*ADDR_WIDTH +: ADDR_WIDTH]    = addr;
      master_a_mask[idx*MASK_WIDTH +: MASK_WIDTH]       = 4'b1111;
      
      wait(master_a_ready[master_id]);
      @(posedge clk_100);
      master_a_valid[master_id] = 1'b0;
      $display($time, " ns: Master %0d Get issued: Addr=0x%0h", master_id, addr);
    end
  endtask

  // ------------------ Slave Response Process ------------------
  initial begin : slave_response_proc
    reg [OPCODE_WIDTH-1:0] req_opcode;
    reg [SRC_WIDTH-1:0] req_source;
    forever begin
      // Wait for valid request
      do begin
        @(posedge clk_24);
      end while (!slave_a_valid);

      // Acknowledge request
      slave_a_ready <= 1'b1;
      @(posedge clk_24);
      slave_a_ready <= 1'b0;

      // Capture request details
      req_opcode = slave_a_opcode;
      req_source = slave_a_source;
      $display($time, " ns: Slave received request: opcode=%0d, source=%0d", req_opcode, req_source);

      // Generate response after random delay (1-3 cycles)
      repeat ($urandom_range(1, 3)) @(posedge clk_24);

      // Drive response channel
      slave_d_valid <= 1'b1;
      slave_d_opcode <= (req_opcode == 4) ? 3'd1 : 3'd0; // Response for Get request
      slave_d_data   <= (req_opcode == 4) ? 32'hDEADBEEF : 32'd0; // Fixed response data
      slave_d_param  <= 3'd0;
      slave_d_size   <= 3'd2;
      slave_d_source <= req_source;
      slave_d_sink   <= 1'b0;
      slave_d_error  <= 1'b0;

      // Wait for ready handshake
      do begin
        @(posedge clk_24);
      end while (!slave_d_ready);

      @(posedge clk_24);
      slave_d_valid <= 1'b0;
      $display($time, " ns: Slave response sent for source=%0d", req_source);
    end
  end

  // ------------------ Master Response Monitoring ------------------
  initial begin : master_response_monitor
    integer m;
    forever begin
      @(posedge clk_100);
      for (m = 0; m < NUM_MASTERS; m = m + 1) begin
        if (master_d_valid[m] && master_d_ready[m]) begin
          $display($time, " ns: Master %0d received response: opcode=%0d, data=0x%0h", 
                   m, master_d_opcode[m*OPCODE_WIDTH +: OPCODE_WIDTH], 
                   master_d_data[m*DATA_WIDTH +: DATA_WIDTH]);
        end
      end
    end
  end

  // ------------------ Debug Initialization ------------------
  initial begin
    $dumpfile("waveform.vcd");
    $dumpvars(0, tlul_interconnect_tb);
  end

  // ------------------ Test Sequence ------------------
  initial begin
    // Initialize all inputs
    foreach (master_a_valid[i]) master_a_valid[i] = 1'b0;
    master_d_ready = '1;
    slave_a_ready = 1'b0;
    slave_d_valid = 1'b0;

    @(negedge reset);
    #30;

    fork
      begin
        drive_put(0, 32'h0000_1000, 32'hA5A5_A5A5);
        #50;
        drive_get(0, 32'h0000_4000);
      end
      begin
        #20;
        drive_get(1, 32'h0000_2000);
        #50;
        drive_put(1, 32'h0000_5000, 32'h1111_2222);
      end
      begin
        #40;
        drive_put(2, 32'h0000_3000, 32'h5A5A_5A5A);
        #50;
        drive_get(2, 32'h0000_6000);
      end
    join

    // Let the simulation run for 100,000 ns
    #100000;
    $display("--- Simulation Complete ---");
    $finish;
  end

endmodule