
module sseg_decoder
(
    input  wire [13 : 0] num,
    input  wire [1  : 0] dig_sel,
    output wire [3  : 0] an_data,
    output reg  [6  : 0] cat_data
);
    
    assign an_data = 1'b1 << dig_sel;

    reg [3 : 0] dig_data;
    
    always @*
        case (dig_sel)
            2'd0 : dig_data = (num / 1) % 10;
            2'd1 : dig_data = (num / 10) % 10;
            2'd2 : dig_data = (num / 100) % 10;
            2'd3 : dig_data = (num / 1000) % 10;
         default : dig_data = 0;
        endcase
    // wire [3 : 0] dig_data = (num / 10 ** dig_sel) % 10;
    
    always @*
        case (dig_data)
            4'd0 : cat_data = 7'b0111111;
            4'd1 : cat_data = 7'b0000110;
            4'd2 : cat_data = 7'b1011011;
            4'd3 : cat_data = 7'b1001111;
            4'd4 : cat_data = 7'b1100110;
            4'd5 : cat_data = 7'b1101101;
            4'd6 : cat_data = 7'b1111101;
            4'd7 : cat_data = 7'b0000111;
            4'd8 : cat_data = 7'b1111111;
            4'd9 : cat_data = 7'b1100111;
         default : cat_data = 0;
        endcase

endmodule // sseg_decoder
