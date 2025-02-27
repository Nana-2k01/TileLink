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
  // Master-side inputs (from master sockets)
  input  logic [NUM_MASTERS-1:0] a_valid,
  output logic [NUM_MASTERS-1:0] a_ready,
  input  logic [NUM_MASTERS*OPCODE_WIDTH-1:0] a_opcode,
  input  logic [NUM_MASTERS*PARAM_WIDTH-1:0]  a_param,
  input  logic [NUM_MASTERS*SIZE_WIDTH-1:0]   a_size,
  input  logic [NUM_MASTERS*SRC_WIDTH-1:0]      a_source,
  input  logic [NUM_MASTERS*ADDR_WIDTH-1:0]     a_address,
  input  logic [NUM_MASTERS*MASK_WIDTH-1:0]     a_mask,
  input  logic [NUM_MASTERS*DATA_WIDTH-1:0]     a_data,
  
  // Master-side response inputs (from masters)
  output logic [NUM_MASTERS-1:0] d_valid,
  input  logic [NUM_MASTERS-1:0] d_ready,
  output logic [NUM_MASTERS*OPCODE_WIDTH-1:0] d_opcode,
  output logic [NUM_MASTERS*PARAM_WIDTH-1:0]  d_param,
  output logic [NUM_MASTERS*SIZE_WIDTH-1:0]   d_size,
  output logic [NUM_MASTERS*SRC_WIDTH-1:0]      d_source,
  output logic [NUM_MASTERS*SINK_WIDTH-1:0]     d_sink,
  output logic [NUM_MASTERS*DATA_WIDTH-1:0]     d_data,
  output logic [NUM_MASTERS-1:0] d_error,
  
  // Outputs toward the CDC adapter (slave-side of xbar_main)
  output logic a_valid_out,
  input  logic a_ready_out,
  output logic [OPCODE_WIDTH-1:0] a_opcode_out,
  output logic [PARAM_WIDTH-1:0]  a_param_out,
  output logic [SIZE_WIDTH-1:0]   a_size_out,
  output logic [SRC_WIDTH-1:0]    a_source_out,
  output logic [ADDR_WIDTH-1:0]   a_address_out,
  output logic [MASK_WIDTH-1:0]   a_mask_out,
  output logic [DATA_WIDTH-1:0]   a_data_out,
  
  input  logic d_valid_in,
  output logic d_ready_in,
  input  logic [OPCODE_WIDTH-1:0] d_opcode_in,
  input  logic [PARAM_WIDTH-1:0]  d_param_in,
  input  logic [SIZE_WIDTH-1:0]   d_size_in,
  input  logic [SRC_WIDTH-1:0]    d_source_in,
  input  logic [SINK_WIDTH-1:0]   d_sink_in,
  input  logic [DATA_WIDTH-1:0]   d_data_in,
  input  logic d_error_in
);

  //--------------------------------------------------------------------------
  // FIFO arbitration for masters.
  // A FIFO queue holds the indices of masters that have asserted a_valid.
  //--------------------------------------------------------------------------

  // FIFO registers: each entry is an index [0, NUM_MASTERS-1]
  reg [$clog2(NUM_MASTERS)-1:0] req_fifo [0:NUM_MASTERS-1];
  reg [$clog2(NUM_MASTERS+1)-1:0] fifo_count;
  reg [$clog2(NUM_MASTERS)-1:0] head, tail;

  // Registered copy of the input valid signals to detect handshake completion.
  reg [NUM_MASTERS-1:0] prev_valid;

  // Current master being served.
  reg [$clog2(NUM_MASTERS)-1:0] current_master;

  // Function to check if a given master index is already in the FIFO.
  function automatic logic master_in_fifo(input logic [$clog2(NUM_MASTERS)-1:0] master);
    integer k;
    logic found;
    begin
      found = 1'b0;
      for (k = 0; k < fifo_count; k = k + 1) begin
        if (req_fifo[(head + k) % NUM_MASTERS] == master)
          found = 1'b1;
      end
      master_in_fifo = found;
    end
  endfunction

  integer i;
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      fifo_count     <= 0;
      head           <= 0;
      tail           <= 0;
      current_master <= 0;
      prev_valid     <= '0;
    end else begin
      // Save a snapshot of the current valid signals.
      prev_valid <= a_valid;

      // Enqueue new requests (if not already queued)
      for (i = 0; i < NUM_MASTERS; i = i + 1) begin
        if (a_valid[i] && !master_in_fifo(i)) begin
          if (fifo_count < NUM_MASTERS) begin
            req_fifo[tail] <= i[$clog2(NUM_MASTERS)-1:0];
            tail           <= (tail + 1) % NUM_MASTERS;
            fifo_count     <= fifo_count + 1;
          end
        end
      end

      // Select current master as the FIFO head (if any request is pending)
      if (fifo_count > 0)
        current_master <= req_fifo[head];
      else
        current_master <= 0;

      // When the current master completes its handshake, i.e.
      // when it was valid in the previous cycle and now deasserted,
      // pop it from the FIFO.
      if (fifo_count > 0 && prev_valid[req_fifo[head]] && !a_valid[req_fifo[head]]) begin
        head       <= (head + 1) % NUM_MASTERS;
        fifo_count <= fifo_count - 1;
      end
    end
  end

  //--------------------------------------------------------------------------
  // Drive a_ready: only the currently served master receives a_ready.
  //--------------------------------------------------------------------------

  genvar j;
  generate
    for (j = 0; j < NUM_MASTERS; j = j+1) begin: gen_a_ready
      assign a_ready[j] = (j == current_master) ? a_ready_out : 1'b0;
    end
  endgenerate

  //--------------------------------------------------------------------------
  // Functions to extract per-master slices from concatenated buses.
  //--------------------------------------------------------------------------

  function automatic [OPCODE_WIDTH-1:0] get_opcode(input integer idx, input logic [NUM_MASTERS*OPCODE_WIDTH-1:0] vec);
    get_opcode = vec[idx*OPCODE_WIDTH +: OPCODE_WIDTH];
  endfunction
  function automatic [PARAM_WIDTH-1:0] get_param(input integer idx, input logic [NUM_MASTERS*PARAM_WIDTH-1:0] vec);
    get_param = vec[idx*PARAM_WIDTH +: PARAM_WIDTH];
  endfunction
  function automatic [SIZE_WIDTH-1:0] get_size(input integer idx, input logic [NUM_MASTERS*SIZE_WIDTH-1:0] vec);
    get_size = vec[idx*SIZE_WIDTH +: SIZE_WIDTH];
  endfunction
  function automatic [SRC_WIDTH-1:0] get_source(input integer idx, input logic [NUM_MASTERS*SRC_WIDTH-1:0] vec);
    get_source = vec[idx*SRC_WIDTH +: SRC_WIDTH];
  endfunction
  function automatic [ADDR_WIDTH-1:0] get_address(input integer idx, input logic [NUM_MASTERS*ADDR_WIDTH-1:0] vec);
    get_address = vec[idx*ADDR_WIDTH +: ADDR_WIDTH];
  endfunction
  function automatic [MASK_WIDTH-1:0] get_mask(input integer idx, input logic [NUM_MASTERS*MASK_WIDTH-1:0] vec);
    get_mask = vec[idx*MASK_WIDTH +: MASK_WIDTH];
  endfunction
  function automatic [DATA_WIDTH-1:0] get_data(input integer idx, input logic [NUM_MASTERS*DATA_WIDTH-1:0] vec);
    get_data = vec[idx*DATA_WIDTH +: DATA_WIDTH];
  endfunction

  //--------------------------------------------------------------------------
  // Demultiplex response signals to each master.
  //--------------------------------------------------------------------------

  generate
    for (j = 0; j < NUM_MASTERS; j = j+1) begin: gen_d_resp
      assign d_valid[j] = (d_source_in == j) ? d_valid_in : 1'b0;
      assign d_opcode[j*OPCODE_WIDTH +: OPCODE_WIDTH] = d_opcode_in;
      assign d_param[j*PARAM_WIDTH +: PARAM_WIDTH]   = d_param_in;
      assign d_size[j*SIZE_WIDTH +: SIZE_WIDTH]        = d_size_in;
      assign d_source[j*SRC_WIDTH +: SRC_WIDTH]          = d_source_in;
      assign d_sink[j*SINK_WIDTH +: SINK_WIDTH]          = d_sink_in;
      assign d_data[j*DATA_WIDTH +: DATA_WIDTH]          = d_data_in;
      assign d_error[j] = d_error_in;
    end
  endgenerate

  // The d_ready signal is passed from the selected master.
  assign d_ready_in = d_ready[current_master];

  // Drive the output signals from the currently selected master.
  assign a_valid_out   = a_valid[current_master];
  assign a_opcode_out  = get_opcode(current_master, a_opcode);
  assign a_param_out   = get_param(current_master, a_param);
  assign a_size_out    = get_size(current_master, a_size);
  assign a_source_out  = get_source(current_master, a_source);
  assign a_address_out = get_address(current_master, a_address);
  assign a_mask_out    = get_mask(current_master, a_mask);
  assign a_data_out    = get_data(current_master, a_data);

endmodule