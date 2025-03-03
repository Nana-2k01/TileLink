// xbar_main.sv - Fixed 3 masters configuration using round-robin arbitration
module xbar_main #(
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
  input  logic [2:0]               a_valid,
  output logic [2:0]               a_ready,
  input  logic [3*OPCODE_WIDTH-1:0]  a_opcode,
  input  logic [3*PARAM_WIDTH-1:0]   a_param,
  input  logic [3*SIZE_WIDTH-1:0]    a_size,
  input  logic [3*SRC_WIDTH-1:0]     a_source,
  input  logic [3*ADDR_WIDTH-1:0]    a_address,
  input  logic [3*MASK_WIDTH-1:0]    a_mask,
  input  logic [3*DATA_WIDTH-1:0]    a_data,
  // Master-side Channel D outputs (to masters)
  output logic [2:0]               d_valid,
  input  logic [2:0]               d_ready,
  output logic [3*OPCODE_WIDTH-1:0]  d_opcode,
  output logic [3*PARAM_WIDTH-1:0]   d_param,
  output logic [3*SIZE_WIDTH-1:0]    d_size,
  output logic [3*SRC_WIDTH-1:0]     d_source,
  output logic [3*SINK_WIDTH-1:0]    d_sink,
  output logic [3*DATA_WIDTH-1:0]    d_data,
  output logic [2:0]               d_error,
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

  // --- Round-Robin Arbitration for Channel A ---
  // We'll use a simple register "grant" that holds the index (0,1,2) of the current master granted.
  // Every clock cycle, if the current master is not asserting a_valid,
  // we scan the other masters (in round-robin order) to find a valid request.
  reg [1:0] grant;
  integer i;
  logic [1:0] candidate;
  
  always @(posedge clk or posedge reset) begin
    if (reset) begin
      grant <= 0;
    end else begin
      if (!a_valid[grant]) begin
        candidate = (grant + 1) % 3;
        // Look through all masters starting from candidate
        for (i = 0; i < 3; i = i + 1) begin
          if (a_valid[candidate]) begin
            grant <= candidate;
            break;
          end
          candidate = (candidate + 1) % 3;
        end
      end
      // Otherwise, keep the current grant if it remains valid.
    end
  end

  // Forward the selected master’s signals to the CDC adapter.
  assign a_valid_out   = a_valid[grant];
  assign a_opcode_out  = a_opcode[grant*OPCODE_WIDTH +: OPCODE_WIDTH];
  assign a_param_out   = a_param[grant*PARAM_WIDTH +: PARAM_WIDTH];
  assign a_size_out    = a_size[grant*SIZE_WIDTH +: SIZE_WIDTH];
  assign a_source_out  = grant;  // Use the grant as the source identifier.
  assign a_address_out = a_address[grant*ADDR_WIDTH +: ADDR_WIDTH];
  assign a_mask_out    = a_mask[grant*MASK_WIDTH +: MASK_WIDTH];
  assign a_data_out    = a_data[grant*DATA_WIDTH +: DATA_WIDTH];

  // Only the granted master gets a_ready asserted.
  genvar j;
  generate for (j = 0; j < 3; j++) begin : gen_a_ready
    assign a_ready[j] = (j == grant) ? a_ready_out : 1'b0;
  end endgenerate

  // --- Channel D Response Demultiplexing ---
  // For Channel D responses coming from the CDC adapter, use d_source_in to route the response to the correct master.
  // (This part remains as before.)
  generate for (j = 0; j < 3; j++) begin : gen_d_resp
    assign d_valid[j]                              = (d_source_in == j) ? d_valid_in : 1'b0;
    assign d_opcode[j*OPCODE_WIDTH +: OPCODE_WIDTH] = d_opcode_in;
    assign d_param[j*PARAM_WIDTH +: PARAM_WIDTH]    = d_param_in;
    assign d_size[j*SIZE_WIDTH +: SIZE_WIDTH]       = d_size_in;
    assign d_source[j*SRC_WIDTH +: SRC_WIDTH]       = d_source_in;
    assign d_sink[j*SINK_WIDTH +: SINK_WIDTH]         = d_sink_in;
    assign d_data[j*DATA_WIDTH +: DATA_WIDTH]       = d_data_in;
    assign d_error[j]                              = d_error_in;
  end endgenerate

  // Route the response ready signal to the appropriate master based on d_source_in.
  always @* begin
    d_ready_in = 1'b0;
    for (int m = 0; m < 3; m++) begin
      if (d_source_in == m) begin
        d_ready_in = d_ready[m];
      end
    end
  end

  // (Optional) Debug prints to observe arbitration and response routing.
  always @(posedge clk or posedge reset) begin
    if (!reset) begin
      $display("[%t] Arbiter grant = Master %0d", $time, grant);
      if (a_valid_out && a_ready_out)
        $display("[%t] Forwarded request from Master %0d (opcode=%0d, addr=0x%0h) to CDC",
                 $time, grant, a_opcode_out, a_address_out);
    end
  end

endmodule
