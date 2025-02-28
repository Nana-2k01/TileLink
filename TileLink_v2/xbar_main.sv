module xbar_main #(
  parameter NUM_MASTERS  = 3,
  parameter ADDR_WIDTH   = 32,
  parameter DATA_WIDTH   = 32,
  parameter MASK_WIDTH   = DATA_WIDTH/8,
  parameter SIZE_WIDTH   = 3,
  parameter SRC_WIDTH    = 2,
  parameter SINK_WIDTH   = 1,
  parameter OPCODE_WIDTH = 3,
  parameter PARAM_WIDTH  = 3
)(
  input  logic clk,
  input  logic reset,
  // Master-side Channel A inputs
  input  logic [NUM_MASTERS-1:0]               a_valid,
  output logic [NUM_MASTERS-1:0]               a_ready,
  input  logic [NUM_MASTERS*OPCODE_WIDTH-1:0]  a_opcode,
  input  logic [NUM_MASTERS*PARAM_WIDTH-1:0]   a_param,
  input  logic [NUM_MASTERS*SIZE_WIDTH-1:0]    a_size,
  input  logic [NUM_MASTERS*SRC_WIDTH-1:0]     a_source,
  input  logic [NUM_MASTERS*ADDR_WIDTH-1:0]    a_address,
  input  logic [NUM_MASTERS*MASK_WIDTH-1:0]    a_mask,
  input  logic [NUM_MASTERS*DATA_WIDTH-1:0]    a_data,
  // Master-side Channel D outputs (to masters)
  output logic [NUM_MASTERS-1:0]               d_valid,
  input  logic [NUM_MASTERS-1:0]               d_ready,
  output logic [NUM_MASTERS*OPCODE_WIDTH-1:0]  d_opcode,
  output logic [NUM_MASTERS*PARAM_WIDTH-1:0]   d_param,
  output logic [NUM_MASTERS*SIZE_WIDTH-1:0]    d_size,
  output logic [NUM_MASTERS*SRC_WIDTH-1:0]     d_source,
  output logic [NUM_MASTERS*SINK_WIDTH-1:0]    d_sink,
  output logic [NUM_MASTERS*DATA_WIDTH-1:0]    d_data,
  output logic [NUM_MASTERS-1:0]               d_error,
  // Outputs to CDC adapter (Channel A)
  output logic        a_valid_out,
  input  logic        a_ready_out,
  output logic [OPCODE_WIDTH-1:0] a_opcode_out,
  output logic [PARAM_WIDTH-1:0]  a_param_out,
  output logic [SIZE_WIDTH-1:0]   a_size_out,
  output logic [SRC_WIDTH-1:0]    a_source_out,
  output logic [ADDR_WIDTH-1:0]   a_address_out,
  output logic [MASK_WIDTH-1:0]   a_mask_out,
  output logic [DATA_WIDTH-1:0]   a_data_out,
  // Inputs from CDC adapter (Channel D)
  input  logic        d_valid_in,
  output logic        d_ready_in,
  input  logic [OPCODE_WIDTH-1:0] d_opcode_in,
  input  logic [PARAM_WIDTH-1:0]  d_param_in,
  input  logic [SIZE_WIDTH-1:0]   d_size_in,
  input  logic [SRC_WIDTH-1:0]    d_source_in,
  input  logic [SINK_WIDTH-1:0]   d_sink_in,
  input  logic [DATA_WIDTH-1:0]   d_data_in,
  input  logic        d_error_in
);

  // Simple FIFO (circular buffer) to enqueue pending master requests
  reg [$clog2(NUM_MASTERS)-1:0] req_fifo [0:NUM_MASTERS-1];
  reg [$clog2(NUM_MASTERS+1)-1:0] fifo_count = 0;
  reg [$clog2(NUM_MASTERS)-1:0] head = 0, tail = 0;
  reg [$clog2(NUM_MASTERS)-1:0] current_master = 0;

  wire handshake = a_valid_out && a_ready_out;

  // Helper: check if a master ID is already enqueued
  function automatic logic master_in_fifo(input logic [$clog2(NUM_MASTERS)-1:0] master);
    for (int k = 0; k < fifo_count; k++) begin
      if (req_fifo[(head + k) % NUM_MASTERS] == master) return 1;
    end
    return 0;
  endfunction

  // Arbitration and enqueue logic (runs every clock)
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      fifo_count     <= 0;
      head           <= 0;
      tail           <= 0;
      current_master <= 0;
    end else begin
      // Enqueue new requests from any masters asserting valid (if not already in queue)
      for (int i = 0; i < NUM_MASTERS; i++) begin
        if (a_valid[i] && !master_in_fifo(i) && fifo_count < NUM_MASTERS) begin
          req_fifo[tail] <= i;
          tail           <= (tail + 1) % NUM_MASTERS;
          fifo_count     <= fifo_count + 1;
          $display("[%t] Master %0d enqueued request (opcode=%0d, addr=0x%0h)", $time, i,
                   a_opcode[i*OPCODE_WIDTH +: OPCODE_WIDTH],
                   a_address[i*ADDR_WIDTH +: ADDR_WIDTH]);
        end
      end

      // Dequeue on a successful handshake (request forwarded to CDC)
      if (handshake && fifo_count > 0) begin
        $display("[%t] Forwarded request from Master %0d to CDC (opcode=%0d, addr=0x%0h)", 
                 $time, current_master, a_opcode_out, a_address_out);
        head       <= (head + 1) % NUM_MASTERS;
        fifo_count <= fifo_count - 1;
      end

      // Update current_master to the next in FIFO (or hold if none pending)
      if (fifo_count > 0)
        current_master <= req_fifo[head];
      // If fifo_count is 0, current_master remains last value (no new request to service)
    end
  end

  // Drive a_ready for masters: only the current_master gets `a_ready_out`, others get 0.
  generate
    for (genvar j = 0; j < NUM_MASTERS; j++) begin : gen_a_ready
      assign a_ready[j] = (j == current_master) ? a_ready_out : 1'b0;
    end
  endgenerate

  // Demultiplex incoming response (Channel D) to the correct master
  generate
    for (genvar j = 0; j < NUM_MASTERS; j++) begin : gen_d_resp
      assign d_valid[j]                              = (d_source_in == j) ? d_valid_in : 1'b0;
      assign d_opcode[j*OPCODE_WIDTH +: OPCODE_WIDTH] = d_opcode_in;
      assign d_param[j*PARAM_WIDTH +: PARAM_WIDTH]    = d_param_in;
      assign d_size[j*SIZE_WIDTH +: SIZE_WIDTH]       = d_size_in;
      assign d_source[j*SRC_WIDTH +: SRC_WIDTH]       = d_source_in;
      assign d_sink[j*SINK_WIDTH +: SINK_WIDTH]       = d_sink_in;
      assign d_data[j*DATA_WIDTH +: DATA_WIDTH]       = d_data_in;
      assign d_error[j]                              = d_error_in;
    end
  endgenerate

  // Drive Channel A outputs to CDC adapter from current_master
  assign a_valid_out   = a_valid[current_master];
  assign a_opcode_out  = a_opcode[current_master*OPCODE_WIDTH +: OPCODE_WIDTH];
  assign a_param_out   = a_param[current_master*PARAM_WIDTH +: PARAM_WIDTH];
  assign a_size_out    = a_size[current_master*SIZE_WIDTH +: SIZE_WIDTH];
  assign a_source_out  = a_source[current_master*SRC_WIDTH +: SRC_WIDTH];
  assign a_address_out = a_address[current_master*ADDR_WIDTH +: ADDR_WIDTH];
  assign a_mask_out    = a_mask[current_master*MASK_WIDTH +: MASK_WIDTH];
  assign a_data_out    = a_data[current_master*DATA_WIDTH +: DATA_WIDTH];

  // Dynamically route Channel D ready to the appropriate master (based on source ID)
  always_comb begin
    d_ready_in = 1'b0;
    for (int m = 0; m < NUM_MASTERS; m++) begin
      if (d_source_in == m) begin
        d_ready_in = d_ready[m];
      end
    end
  end

  // Monitor Channel D responses delivered to masters
  always_ff @(posedge clk or posedge reset) begin
    if (!reset) begin
      if (d_valid_in && d_ready_in) begin
        $display("[%t] Response returned from slave (opcode=%0d) to Master %0d",
                 $time, d_opcode_in, d_source_in);
      end
    end
  end

endmodule
