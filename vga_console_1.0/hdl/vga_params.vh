
`ifndef VGA_PARAMS_VH
`define VGA_PARAMS_VH

    // 1280 x 720
    // 74 MHz pixel clock
    // ~60 FPS

    // Horizontal timing
    localparam H_FRONT  = 110;
    localparam H_ACTIVE = 1280;
    localparam H_BACK   = 220;
    localparam H_SYNC   = 40;

    // Vertical timing
    localparam V_FRONT  = 5;
    localparam V_ACTIVE = 720;
    localparam V_BACK   = 20;
    localparam V_SYNC   = 5;

    // Active region bounds
    localparam H_ACTIVE_MIN = H_FRONT;
    localparam V_ACTIVE_MIN = V_FRONT;
    localparam H_ACTIVE_MAX = H_ACTIVE_MIN + H_ACTIVE - 1;
    localparam V_ACTIVE_MAX = V_ACTIVE_MIN + V_ACTIVE - 1;

    // Syncing region bounds
    localparam H_SYNC_MIN = H_FRONT + H_ACTIVE + H_BACK;
    localparam V_SYNC_MIN = V_FRONT + V_ACTIVE + V_BACK;
    localparam H_SYNC_MAX = H_SYNC_MIN + H_SYNC - 1;
    localparam V_SYNC_MAX = V_SYNC_MIN + V_SYNC - 1;

`endif // VGA_PARAMS_VH
