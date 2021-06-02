
`include "vga_params.vh"

module sync_gen
(
    input wire pix_clk,
    input wire rst,

    output wire [11 : 0] H_count,
    output wire [11 : 0] V_count,

    output wire H_sync,
    output wire V_sync,
    output wire H_active,
    output wire V_active
);

    sync_counter #(.STOP(H_SYNC_MAX)) H_counter
    (
        .pix_clk ( pix_clk ),
        .rst     ( rst     ),
        .en      ( 1'b1    ),
        .val     ( H_count )
    );

    wire V_en = (H_count == H_SYNC_MAX);

    sync_counter #(.STOP(V_SYNC_MAX)) V_counter
    (
        .pix_clk ( pix_clk ),
        .rst     ( rst     ),
        .en      ( V_en    ),
        .val     ( V_count )
    );

    assign H_sync = (H_SYNC_MIN <= H_count) & (H_count <= H_SYNC_MAX);
    assign V_sync = (V_SYNC_MIN <= V_count) & (V_count <= V_SYNC_MAX);

    assign H_active = (H_ACTIVE_MIN <= H_count) & (H_count <= H_ACTIVE_MAX);
    assign V_active = (V_ACTIVE_MIN <= V_count) & (V_count <= V_ACTIVE_MAX);

endmodule // sync_gen
