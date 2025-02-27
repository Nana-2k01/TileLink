// async_fifo.sv
// A simple asynchronous FIFO with parameterizable data width and depth.
// Note: In a production design, ensure that pointer crossing includes at least 2 synchronizer stages.
module async_fifo #(
  parameter DATA_WIDTH = 32,
  parameter DEPTH = 8,
  localparam PTR_WIDTH = $clog2(DEPTH)
)(
  input  logic wr_clk,
  input  logic rd_clk,
  input  logic reset,
  input  logic wr_en,
  input  logic [DATA_WIDTH-1:0] wr_data,
  output logic full,
  input  logic rd_en,
  output logic [DATA_WIDTH-1:0] rd_data,
  output logic empty
);
  logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];
  logic [PTR_WIDTH:0] wr_ptr, rd_ptr;
  
  // Write logic in wr_clk domain
  always_ff @(posedge wr_clk or posedge reset) begin
    if (reset)
      wr_ptr <= 0;
    else if (wr_en && !full) begin
      mem[wr_ptr[PTR_WIDTH-1:0]] <= wr_data;
      wr_ptr <= wr_ptr + 1;
    end
  end
  
  // Read logic in rd_clk domain
  always_ff @(posedge rd_clk or posedge reset) begin
    if (reset)
      rd_ptr <= 0;
    else if (rd_en && !empty)
      rd_ptr <= rd_ptr + 1;
  end
  
  assign rd_data = mem[rd_ptr[PTR_WIDTH-1:0]];
  assign full  = ((wr_ptr - rd_ptr) == DEPTH);
  assign empty = (wr_ptr == rd_ptr);
endmodule
