// async_fifo.sv - A simple dual-clock asynchronous FIFO.
// This module is provided as an example and is Verilator compatible.
module async_fifo #(
  parameter DATA_WIDTH = 8,
  parameter DEPTH = 8
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

  localparam ADDR_WIDTH = $clog2(DEPTH);
  // Memory array
  logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];

  // Write pointer and its synchronizers
  logic [ADDR_WIDTH:0] wr_ptr, wr_ptr_gray, wr_ptr_gray_rd;
  // Read pointer and its synchronizers
  logic [ADDR_WIDTH:0] rd_ptr, rd_ptr_gray, rd_ptr_gray_wr;

  // Write pointer logic (in write clock domain)
  always @(posedge wr_clk or posedge reset) begin
    if (reset)
      wr_ptr <= 0;
    else if (wr_en && !full)
      wr_ptr <= wr_ptr + 1;
  end

  // Convert write pointer to Gray code
  assign wr_ptr_gray = wr_ptr ^ (wr_ptr >> 1);

  // Read pointer logic (in read clock domain)
  always @(posedge rd_clk or posedge reset) begin
    if (reset)
      rd_ptr <= 0;
    else if (rd_en && !empty)
      rd_ptr <= rd_ptr + 1;
  end

  // Convert read pointer to Gray code
  assign rd_ptr_gray = rd_ptr ^ (rd_ptr >> 1);

  // Memory write
  always @(posedge wr_clk) begin
    if (wr_en && !full)
      mem[wr_ptr[ADDR_WIDTH-1:0]] <= wr_data;
  end

  // Memory read
  always @(posedge rd_clk) begin
    if (rd_en && !empty)
      rd_data <= mem[rd_ptr[ADDR_WIDTH-1:0]];
  end

  // Synchronize write pointer into read clock domain
  reg [ADDR_WIDTH:0] wr_ptr_gray_rd_reg;
  always @(posedge rd_clk or posedge reset) begin
    if (reset)
      wr_ptr_gray_rd_reg <= 0;
    else
      wr_ptr_gray_rd_reg <= wr_ptr_gray;
  end
  assign wr_ptr_gray_rd = wr_ptr_gray_rd_reg;

  // Synchronize read pointer into write clock domain
  reg [ADDR_WIDTH:0] rd_ptr_gray_wr_reg;
  always @(posedge wr_clk or posedge reset) begin
    if (reset)
      rd_ptr_gray_wr_reg <= 0;
    else
      rd_ptr_gray_wr_reg <= rd_ptr_gray;
  end
  assign rd_ptr_gray_wr = rd_ptr_gray_wr_reg;

  // Full condition: when next write pointer equals read pointer synchronized to write domain
  // The FIFO is full when the difference between write and read pointer equals DEPTH.
  assign full  = ( (wr_ptr_gray ^ {1'b1, {(ADDR_WIDTH){1'b0}}}) == rd_ptr_gray_wr );

  // Empty condition: when write pointer synchronized to read domain equals read pointer.
  assign empty = (wr_ptr_gray_rd == rd_ptr_gray);

endmodule
