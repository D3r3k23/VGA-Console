
`timescale 1ns / 1ps

module sseg_controller_tb();

    // Inputs
    reg clk;
    reg rst;

    reg [13 : 0] num;

    //Outputs
    wire [3 : 0] an;
    wire [7 : 0] cat;


    // 100 MHz clk gen
    initial   clk = 1'b0;
    always #5 clk <= ~clk;

    sseg_controller dut
    (
        .clk    ( clk  ),
        .rst    ( rst  ),
        .dig_en ( 4'hF ),
        .dp_en  ( 4'h0 ),
        .num    ( num  ),

        .an  ( an  ),
        .cat ( cat )
    );

    initial begin : test
        rst = 1'b1;
        #50
        rst = 1'b0;

        num = 2468;

        #2000000
        $finish;

    end // test

endmodule // sseg_controller_tb
