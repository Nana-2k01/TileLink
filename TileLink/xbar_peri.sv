module xbar_peri (
    input  logic        clk_i,
    input  logic        rst_ni,
    
    // TL-UL interface from xbar_main (host)
    input  tlul_pkg::tl_h2d_t  tl_h2d_main,
    output tlul_pkg::tl_d2h_t  tl_d2h_main,
    
    // TL-UL interface to GPIO (target)
    output tlul_pkg::tl_h2d_t  tl_h2d_gpio,
    input  tlul_pkg::tl_d2h_t  tl_d2h_gpio
);

  // TL-UL 1:1 Socket Instantiation
  tlul_socket_1_1 u_tlul_socket_1_1 (
    .clk_i,
    .rst_ni,
    .tl_h2d_i  (tl_h2d_main),
    .tl_d2h_o  (tl_d2h_main),
    .tl_h2d_o  (tl_h2d_gpio),
    .tl_d2h_i  (tl_d2h_gpio)
  );

endmodule