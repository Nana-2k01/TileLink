module xbar_main (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    // TL-UL interface from CPU (host)
    input  tlul_pkg::tl_h2d_t  tl_h2d_cpu,
    output tlul_pkg::tl_d2h_t  tl_d2h_cpu,
    
    // TL-UL interface to HW Accelerators (target 1 & 2)
    output tlul_pkg::tl_h2d_t  tl_h2d_accel1,
    input  tlul_pkg::tl_d2h_t  tl_d2h_accel1,
    
    output tlul_pkg::tl_h2d_t  tl_h2d_accel2,
    input  tlul_pkg::tl_d2h_t  tl_d2h_accel2
);

  // TL-UL 1:2 Socket Instantiation
  tlul_socket_1n #(
    .N(2)  // 1:2 fan-out
  ) u_tlul_socket_1n (
    .clk_i,
    .rst_ni,
    .tl_h2d_i  (tl_h2d_cpu),
    .tl_d2h_o  (tl_d2h_cpu),
    .tl_h2d_o  ({tl_h2d_accel2, tl_h2d_accel1}),
    .tl_d2h_i  ({tl_d2h_accel2, tl_d2h_accel1})
  );

endmodule