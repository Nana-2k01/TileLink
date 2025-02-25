`timescale 1ns / 1ps

module tlul_testbench;

  // Clock and reset signals
  logic clk_main, clk_peri, rst_n;

  // TL-UL Interfaces
  tlul_pkg::tl_h2d_t tl_h2d_main;
  tlul_pkg::tl_d2h_t tl_d2h_main;
  tlul_pkg::tl_h2d_t tl_h2d_peri;
  tlul_pkg::tl_d2h_t tl_d2h_peri;

  // Instantiate DUT (Device Under Test)
  tlul_cdc_adapter dut (
    .clk_main_i(clk_main),
    .clk_peri_i(clk_peri),
    .rst_ni(rst_n),
    .tl_h2d_main(tl_h2d_main),
    .tl_d2h_main(tl_d2h_main),
    .tl_h2d_peri(tl_h2d_peri),
    .tl_d2h_peri(tl_d2h_peri)
  );

  // Clock Generation
  always #5 clk_main = ~clk_main;  // 100MHz -> 10ns period
  always #20 clk_peri = ~clk_peri; // 24MHz -> ~41.67ns period

  // Reset Logic
  initial begin
    clk_main = 0;
    clk_peri = 0;
    rst_n = 0;
    #100 rst_n = 1; // Deassert reset after 100ns
  end

  // Task for Sending Transactions
  task send_tlul_transaction(input logic [31:0] addr, input logic [31:0] data, input logic write);
    begin
      tl_h2d_main.a_valid = 1'b1;
      tl_h2d_main.a_address = addr;
      tl_h2d_main.a_data = data;
      tl_h2d_main.a_opcode = tlul_pkg::tl_a_op_e'(write ? 3'b010 : 3'b001); // FIX: Qualified enum
      tl_h2d_main.a_size = 2'b10; // 4 bytes
      tl_h2d_main.d_ready = 1'b1;
      
      wait(tl_d2h_main.a_ready);
      $display("[INFO] Sent TL-UL %s transaction to addr 0x%0h, data 0x%0h", (write ? "WRITE" : "READ"), addr, data);
      
      tl_h2d_main.a_valid = 1'b0; // Deassert after handshake
    end
  endtask

  // Test Sequence
  initial begin
    #200; // Wait for reset release
    
    // 1. Test Basic Write Transaction
    send_tlul_transaction(32'h4000_0000, 32'hDEADBEEF, 1'b1);
    #100;
    
    // 2. Test Basic Read Transaction
    send_tlul_transaction(32'h4000_0000, 32'h0, 1'b0);
    #100;
    
    // 3. Test Clock Domain Crossing (CDC)
    fork
      send_tlul_transaction(32'h4000_1000, 32'h12345678, 1'b1);
      #50 send_tlul_transaction(32'h4000_1004, 32'h87654321, 1'b1);
    join
    #200;

    // 4. Test Timeout Handling (No Response)
    tl_h2d_main.a_valid = 1'b1;
    tl_h2d_main.a_address = 32'h5000_0000;
    tl_h2d_main.a_opcode = tlul_pkg::tl_a_op_e'(3'b001); // FIX: Qualified enum
    #500;
    if (dut.timeout_err)
      $display("[ERROR] Timeout detected as expected!");
    else
      $display("[FAIL] Timeout test failed!");
    tl_h2d_main.a_valid = 1'b0;
    
    // 5. Test Backpressure Handling
    tl_h2d_main.a_valid = 1'b1;
    #20;
    tl_h2d_main.a_valid = 1'b0;
    #100;
    
    $display("[INFO] Testbench completed");
    $finish;
  end
endmodule

