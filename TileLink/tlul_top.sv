module tlul_top (
    input  logic        clk_main_i,  // 100MHz clock (CPU + HW Accel)
    input  logic        clk_peri_i,  // 24MHz clock (GPIO)
    input  logic        rst_ni,

    // CPU Interface (Open Port)
    input  tlul_pkg::tl_h2d_t  tl_h2d_cpu,
    output tlul_pkg::tl_d2h_t  tl_d2h_cpu,

    // Hardware Accelerator Interfaces (Open Ports)
    output tlul_pkg::tl_h2d_t  tl_h2d_hwaccel_0,
    input  tlul_pkg::tl_d2h_t  tl_d2h_hwaccel_0,
    output tlul_pkg::tl_h2d_t  tl_h2d_hwaccel_1,
    input  tlul_pkg::tl_d2h_t  tl_d2h_hwaccel_1,

    // GPIO Interface (Open Port)
    output tlul_pkg::tl_h2d_t  tl_h2d_gpio,
    input  tlul_pkg::tl_d2h_t  tl_d2h_gpio
);

    // Crossbar - Main (100MHz Domain)
    xbar_main u_xbar_main (
        .clk_i      (clk_main_i),
        .rst_ni     (rst_ni),

        // CPU as Host
        .tl_h2d_host (tl_h2d_cpu),
        .tl_d2h_host (tl_d2h_cpu),

        // HW Accelerators as Devices
        .tl_h2d_device_0 (tl_h2d_hwaccel_0),
        .tl_d2h_device_0 (tl_d2h_hwaccel_0),
        .tl_h2d_device_1 (tl_h2d_hwaccel_1),
        .tl_d2h_device_1 (tl_d2h_hwaccel_1),

        // Connection to tlul_cdc_adapter
        .tl_h2d_device_2 (tl_h2d_xbar_peri),  // Output to CDC adapter
        .tl_d2h_device_2 (tl_d2h_xbar_peri)   // Response from CDC adapter
    );

    // TL-UL CDC Adapter (100MHz ↔ 24MHz)
    tlul_cdc_adapter u_tlul_cdc_adapter (
        .clk_main_i (clk_main_i),
        .clk_peri_i (clk_peri_i),
        .rst_ni     (rst_ni),

        // Interface to xbar_main (100MHz)
        .tl_h2d_main (tl_h2d_xbar_peri),
        .tl_d2h_main (tl_d2h_xbar_peri),

        // Interface to xbar_peri (24MHz)
        .tl_h2d_peri (tl_h2d_xbar_peri_out),
        .tl_d2h_peri (tl_d2h_xbar_peri_out)
    );

    // Crossbar - Peripheral (24MHz Domain)
    xbar_peri u_xbar_peri (
        .clk_i      (clk_peri_i),
        .rst_ni     (rst_ni),

        // Interface from CDC Adapter
        .tl_h2d_host (tl_h2d_xbar_peri_out),
        .tl_d2h_host (tl_d2h_xbar_peri_out),

        // Interface to GPIO
        .tl_h2d_device_0 (tl_h2d_gpio),
        .tl_d2h_device_0 (tl_d2h_gpio)
    );

endmodule
