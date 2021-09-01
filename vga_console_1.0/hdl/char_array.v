
module char_buffer
#(parameter
    integer WIDTH  = 45,
    integer HEIGHT = 80
 )(
    // Write port
    input wire          w_clk,
    input wire          w_en,
    input wire [7  : 0] w_pos_x,
    input wire [7  : 0] w_pos_y,
    input wire [7  : 0] w_char,
    input wire [11 : 0] w_color,

    // Read port
    input  wire          r_clk,
    input  wire [7  : 0] r_pos_x,
    input  wire [7  : 0] r_pos_y,
    output wire [7  : 0] r_char,
    output wire [11 : 0] r_color
);

    localparam WIDTH  = 80;
    localparam HEIGHT = 45;

    wire [11 : 0] w_addr = w_pos_y * WIDTH + w_pos_x;
    wire [11 : 0] r_addr = r_pos_y * WIDTH + r_pos_x;
    
    wire [19 : 0] w_data = { w_color, w_char };
    wire [19 : 0] r_data;

    blk_mem_gen_0 char_mem // From Block Memory Generator IP
    (
        // Write port
        .clka  ( w_clk  ), // input wire clka
        .wea   ( w_en   ), // input wire [0  : 0] wea
        .addra ( w_addr ), // input wire [11 : 0] addra
        .dina  ( w_data ), // input wire [19 : 0] dina

        // Read port
        .clkb  ( r_clk  ), // input  wire clkb
        .addrb ( r_addr ), // input  wire [11 : 0] addrb
        .doutb ( r_data )  // output wire [19 : 0] doutb
    );

    assign { r_color, r_char } = r_data;

endmodule // char_array
