// xbar_peri.sv
// 24 MHz domain crossbar that connects the CDC adapter to the slave socket.
// For this design, it simply passes through the signals.
// This module is parameterized for future scalability.
module xbar_peri #(
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
  // Input side from CDC adapter (24 MHz domain)
  input  logic a_valid,
  output logic a_ready,
  input  logic [OPCODE_WIDTH-1:0] a_opcode,
  input  logic [PARAM_WIDTH-1:0]  a_param,
  input  logic [SIZE_WIDTH-1:0]   a_size,
  input  logic [SRC_WIDTH-1:0]    a_source,
  input  logic [ADDR_WIDTH-1:0]   a_address,
  input  logic [MASK_WIDTH-1:0]   a_mask,
  input  logic [DATA_WIDTH-1:0]   a_data,
  
  output logic d_valid,
  input  logic d_ready,
  output logic [OPCODE_WIDTH-1:0] d_opcode,
  output logic [PARAM_WIDTH-1:0]  d_param,
  output logic [SIZE_WIDTH-1:0]   d_size,
  output logic [SRC_WIDTH-1:0]    d_source,
  output logic [SINK_WIDTH-1:0]   d_sink,
  output logic [DATA_WIDTH-1:0]   d_data,
  output logic d_error,
  
  // Slave socket interface (exposed to the testbench)
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
  // For now, simply pass through all signals.
  assign a_valid_out  = a_valid;
  assign a_opcode_out = a_opcode;
  assign a_param_out  = a_param;
  assign a_size_out   = a_size;
  assign a_source_out = a_source;
  assign a_address_out= a_address;
  assign a_mask_out   = a_mask;
  assign a_data_out   = a_data;
  assign a_ready      = a_ready_out;
  
  assign d_valid = d_valid_in;
  assign d_opcode = d_opcode_in;
  assign d_param  = d_param_in;
  assign d_size   = d_size_in;
  assign d_source = d_source_in;
  assign d_sink   = d_sink_in;
  assign d_data   = d_data_in;
  assign d_error  = d_error_in;
  assign d_ready_in = d_ready;
endmodule
