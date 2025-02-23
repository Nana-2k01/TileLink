module prim_flop_2sync #(
    parameter WIDTH = 1  // Default width is 1 bit, can be adjusted
)(
    input  logic               clk_i,    // Clock input (destination clock domain)
    input  logic               rst_ni,   // Active-low reset
    input  logic [WIDTH-1:0]   d_i,      // Data input
    output logic [WIDTH-1:0]   q_o       // Synchronized data output
);

    // Internal signals for the synchronized stages
    logic [WIDTH-1:0] sync_1, sync_2;

    // First flip-flop stage (sync to destination clock domain)
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni)
            sync_1 <= '0;  // Reset the first flip-flop
        else
            sync_1 <= d_i; // Transfer data to sync_1
    end

    // Second flip-flop stage (final synchronization)
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni)
            sync_2 <= '0;  // Reset the second flip-flop
        else
            sync_2 <= sync_1; // Transfer data to sync_2
    end

    // Output the synchronized data
    assign q_o = sync_2;

endmodule
