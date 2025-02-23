module tlul_cdc_adapter (
    input  logic        clk_main_i,  // 100MHz clock domain
    input  logic        clk_peri_i,  // 24MHz clock domain
    input  logic        rst_ni,
    
    // TL-UL interface from xbar_main (100MHz domain)
    input  tlul_pkg::tl_h2d_t  tl_h2d_main,
    output tlul_pkg::tl_d2h_t  tl_d2h_main,
    
    // TL-UL interface to xbar_peri (24MHz domain)
    output tlul_pkg::tl_h2d_t  tl_h2d_peri,
    input  tlul_pkg::tl_d2h_t  tl_d2h_peri
);

  logic req_main, ack_main;
  logic req_peri, ack_peri;
  logic rsp_peri, rsp_ack_main;
  logic rsp_main, rsp_ack_peri;
  logic timeout_err, backpressure;
  
  // Synchronizers for request and acknowledge signals
  prim_flop_2sync u_req_sync (
    .clk_i (clk_peri_i),
    .rst_ni(rst_ni),
    .d_i   (req_main),
    .q_o   (req_peri)
  );
  
  prim_flop_2sync u_ack_sync (
    .clk_i (clk_main_i),
    .rst_ni(rst_ni),
    .d_i   (ack_peri),
    .q_o   (ack_main)
  );

  // Synchronizers for response handshake
  prim_flop_2sync u_rsp_sync (
    .clk_i (clk_main_i),
    .rst_ni(rst_ni),
    .d_i   (rsp_peri),
    .q_o   (rsp_main)
  );
  
  prim_flop_2sync u_rsp_ack_sync (
    .clk_i (clk_peri_i),
    .rst_ni(rst_ni),
    .d_i   (rsp_ack_main),
    .q_o   (rsp_ack_peri)
  );

  // Request Handshake Logic
  always_ff @(posedge clk_main_i or negedge rst_ni) begin
    if (!rst_ni) req_main <= 1'b0;
    else if (!req_main && !ack_main) req_main <= 1'b1; // Set request when idle
  end

  always_ff @(posedge clk_peri_i or negedge rst_ni) begin
    if (!rst_ni) ack_peri <= 1'b0;
    else if (req_peri) ack_peri <= 1'b1; // Acknowledge request
  end

  // Response Handshake Logic
  always_ff @(posedge clk_peri_i or negedge rst_ni) begin
    if (!rst_ni) rsp_peri <= 1'b0;
    else if (!rsp_peri && !rsp_ack_peri) rsp_peri <= 1'b1; // Set response when idle
  end

  always_ff @(posedge clk_main_i or negedge rst_ni) begin
    if (!rst_ni) rsp_ack_main <= 1'b0;
    else if (rsp_main) rsp_ack_main <= 1'b1; // Acknowledge response
  end

  // Timeout Detection
  logic [7:0] timeout_cnt;
  always_ff @(posedge clk_main_i or negedge rst_ni) begin
    if (!rst_ni) begin
      timeout_cnt <= 8'd0;
      timeout_err <= 1'b0;
    end else if (req_main && !ack_main) begin
      timeout_cnt <= timeout_cnt + 1;
      if (timeout_cnt == 8'hFF) timeout_err <= 1'b1; // Trigger error on timeout
    end else begin
      timeout_cnt <= 8'd0;
      timeout_err <= 1'b0;
    end
  end

  // Backpressure Handling
  always_ff @(posedge clk_peri_i or negedge rst_ni) begin
    if (!rst_ni) backpressure <= 1'b0;
    else if (!tl_h2d_peri.ready) backpressure <= 1'b1;
    else backpressure <= 1'b0;
  end

  // Asynchronous FIFO for TL-UL request signals with handshake
  tlul_fifo_async u_tlul_fifo_async_req (
    .clk_src_i  (clk_main_i),
    .clk_dst_i  (clk_peri_i),
    .rst_ni     (rst_ni),
    .tl_h2d_i   (tl_h2d_main),
    .tl_h2d_o   (tl_h2d_peri)
  );

  // Asynchronous FIFO for TL-UL response signals with handshake
  tlul_fifo_async u_tlul_fifo_async_rsp (
    .clk_src_i  (clk_peri_i),
    .clk_dst_i  (clk_main_i),
    .rst_ni     (rst_ni),
    .tl_d2h_i   (tl_d2h_peri),
    .tl_d2h_o   (tl_d2h_main)
  );

endmodule