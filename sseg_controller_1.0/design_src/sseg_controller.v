
module sseg_controller
(
    input wire          clk,
    input wire          rst,
    input wire [3  : 0] dig_en,
    input wire [3  : 0] dp_en,
    input wire [13 : 0] num,

    output wire [3 : 0] an,
    output wire [7 : 0] cat
);

    wire div_clk;

    clk_divider #( .DIV(20000) )
    sseg_clk
    (
        .clk_in  ( clk     ),
        .rst     ( rst     ),
        .clk_out ( div_clk )
    );

    reg [1 : 0] dig_sel = 0;

    always @( posedge div_clk )
        dig_sel <= dig_sel + 1;

    wire [3 : 0] an_data;
    wire [6 : 0] cat_data;

    sseg_decoder sseg_decoder_inst
    (
        .num      ( num      ),
        .dig_sel  ( dig_sel  ),
        .an_data  ( an_data  ),
        .cat_data ( cat_data )
    );

    assign an = ~({4{~rst}} & dig_en & an_data);

    assign cat[7] = ~(~rst & dp_en[dig_sel]);

    assign cat[6 : 0] = ({7{~rst}} & dig_en[dig_sel]) ? ~cat_data : 7'd0;

endmodule // sseg_controller
