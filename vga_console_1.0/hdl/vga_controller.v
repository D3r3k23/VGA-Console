
`include "vga_params.vh"

module vga_controller
(
    input wire pix_clk,
    input wire rst,
    input wire en,

    input wire [6  : 0] char,
    input wire [11 : 0] char_color,
    input wire [11 : 0] back_color,

    output wire [11 : 0] pix_x,
    output wire [11 : 0] pix_y,

    output wire [3 : 0] pix_R,
    output wire [3 : 0] pix_G,
    output wire [3 : 0] pix_B,

    output wire hsync,
    output wire vsync,
    output wire vid_active,

    output wire new_frame
);

    wire [11 : 0] H_count, V_count;
    wire          H_active, V_active;

    sync_gen sync_gen_inst
    (
        .pix_clk ( pix_clk ),
        .rst     ( rst     ),

        .H_count ( H_count ),
        .V_count ( V_count ),

        .H_sync   ( hsync    ),
        .V_sync   ( vsync    ),
        .H_active ( H_active ),
        .V_active ( V_active )
    );

    assign new_frame  = hsync & vsync;
    assign vid_active = H_active & V_active;

    // Active region pixel coordinates
    assign pix_x = vid_active ? (H_count - H_FRONT) : 0;
    assign pix_y = vid_active ? (V_count - V_FRONT) : 0;

    // Character tile coordinates
    wire [3 : 0] char_tile_x = (pix_x + 1) % 16; // char ROM latency: 1 clk
    wire [3 : 0] char_tile_y = pix_y % 16;

    wire [11 : 0] pix_color;

    pixel_gen pixel_gen_inst
    (
        // Inputs
        .pix_clk ( pix_clk ),
        .rst     ( rst     ),
        .en      ( en      ),

        .char       ( char       ),
        .char_color ( char_color ),
        .back_color ( back_color ),

        .vid_active ( vid_active  ),
        .tile_x     ( char_tile_x ),
        .tile_y     ( char_tile_y ),

        // Outputs
        .pix_color ( pix_color )
    );

    assign { pix_R, pix_G, pix_B } = pix_color;

endmodule // vga_controller
