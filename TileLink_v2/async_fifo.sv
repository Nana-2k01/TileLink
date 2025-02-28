module asynch_fifo #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 4    // FIFO depth = 2^ADDR_WIDTH
)(
    input  logic                 wr_clk,
    input  logic                 wr_reset_n,
    input  logic                 wr_en,
    input  logic [DATA_WIDTH-1:0] wr_data,
    output logic                 wr_full,
    
    input  logic                 rd_clk,
    input  logic                 rd_reset_n,
    input  logic                 rd_en,
    output logic [DATA_WIDTH-1:0] rd_data,
    output logic                 rd_empty
);
    // Internal storage (depth = 2^ADDR_WIDTH entries)
    localparam DEPTH = (1 << ADDR_WIDTH);
    logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];

    // Binary and Gray-coded pointers for write and read
    logic [ADDR_WIDTH:0] wr_ptr_bin, wr_ptr_gray;
    logic [ADDR_WIDTH:0] rd_ptr_bin, rd_ptr_gray;
    logic [ADDR_WIDTH:0] wr_ptr_bin_next, wr_ptr_gray_next;
    logic [ADDR_WIDTH:0] rd_ptr_bin_next, rd_ptr_gray_next;

    // Pointer synchronization registers (Gray code) for cross-clock comparison
    logic [ADDR_WIDTH:0] rd_ptr_gray_sync, rd_ptr_gray_sync2;
    logic [ADDR_WIDTH:0] wr_ptr_gray_sync, wr_ptr_gray_sync2;

    // Write pointer logic (in write clock domain)
    always_ff @(posedge wr_clk or negedge wr_reset_n) begin
        if (!wr_reset_n) begin
            wr_ptr_bin  <= '0;
            wr_ptr_gray <= '0;
        end else begin
            if (wr_en && !wr_full) begin
                // Write data into FIFO
                mem[wr_ptr_bin[ADDR_WIDTH-1:0]] <= wr_data;
                // Increment write pointer (binary and Gray)
                wr_ptr_bin  <= wr_ptr_bin + 1;
                wr_ptr_gray <= (wr_ptr_bin + 1) ^ ((wr_ptr_bin + 1) >> 1);
            end
        end
    end

    // Read pointer logic (in read clock domain)
    always_ff @(posedge rd_clk or negedge rd_reset_n) begin
        if (!rd_reset_n) begin
            rd_ptr_bin  <= '0;
            rd_ptr_gray <= '0;
        end else begin
            if (rd_en && !rd_empty) begin
                // Increment read pointer (binary and Gray)
                rd_ptr_bin  <= rd_ptr_bin + 1;
                rd_ptr_gray <= (rd_ptr_bin + 1) ^ ((rd_ptr_bin + 1) >> 1);
            end
        end
    end

    // Read data output (combinationally read from memory)
    assign rd_data = mem[rd_ptr_bin[ADDR_WIDTH-1:0]];

    // Synchronize read pointer into write-clock domain (for fullness check)
    always_ff @(posedge wr_clk or negedge wr_reset_n) begin
        if (!wr_reset_n) begin
            rd_ptr_gray_sync  <= '0;
            rd_ptr_gray_sync2 <= '0;
        end else begin
            rd_ptr_gray_sync  <= rd_ptr_gray;
            rd_ptr_gray_sync2 <= rd_ptr_gray_sync;
        end
    end

    // Synchronize write pointer into read-clock domain (for emptiness check)
    always_ff @(posedge rd_clk or negedge rd_reset_n) begin
        if (!rd_reset_n) begin
            wr_ptr_gray_sync  <= '0;
            wr_ptr_gray_sync2 <= '0;
        end else begin
            wr_ptr_gray_sync  <= wr_ptr_gray;
            wr_ptr_gray_sync2 <= wr_ptr_gray_sync;
        end
    end

    // Compute next write pointer (binary and Gray, for full detection)
    assign wr_ptr_bin_next  = wr_ptr_bin + 1;
    assign wr_ptr_gray_next = wr_ptr_bin_next ^ (wr_ptr_bin_next >> 1);

    // Full condition: next write pointer Gray equals read pointer Gray (synced) with MSB differenced
    assign wr_full = (wr_ptr_gray_next == {~rd_ptr_gray_sync2[ADDR_WIDTH], rd_ptr_gray_sync2[ADDR_WIDTH-1:0]});
    // Empty condition: read pointer Gray equals synchronized write pointer Gray
    assign rd_empty = (rd_ptr_gray == wr_ptr_gray_sync2);

endmodule
