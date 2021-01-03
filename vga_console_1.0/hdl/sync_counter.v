
module sync_counter
#(parameter
    integer STOP = 255
)(
    input wire pix_clk,
    input wire rst,
    input wire en,

    output reg [11 : 0] val
);

    always @( posedge pix_clk )
        if (rst)
            val <= 0;
        else if (en)
        begin
            if (val == STOP)
                val <= 0;
            else
                val <= val + 1;
        end
        else
            val <= val;

endmodule
