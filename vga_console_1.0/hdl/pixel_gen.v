
module pixel_gen
(
    input wire pix_clk,
    input wire rst,
    input wire en,

    input wire [6  : 0] char,
    input wire [11 : 0] char_color,
    input wire [11 : 0] back_color,

    input wire         vid_active,
    input wire [3 : 0] tile_x,
    input wire [3 : 0] tile_y,
    
    output reg [11 : 0] pix_color
);

    wire [3  : 0] line_addr     = 15 - tile_y;
    wire [10 : 0] char_rom_addr = { char, line_addr };
    wire [15 : 0] char_rom_data;

    char_rom char_rom_inst
    (
        .DO    ( char_rom_data ),
        .ADDR  ( char_rom_addr ),
        .CLK   ( pix_clk       ),
        .DI    ( 16'd0         ),
        .EN    ( 1'b1          ),
        .REGCE ( 1'b1          ),
        .RST   ( rst           ),
        .WE    ( 2'd0          )
    );

    wire pix_is_char = char_rom_data[15 - tile_x];

    always @*
        if (~rst && en && vid_active)
        begin
            if (pix_is_char)
                pix_color = char_color;
            else
                pix_color = back_color;
        end
        else
            pix_color = 12'd0;

endmodule
