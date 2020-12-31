
#ifndef VGA_CONSOLE_H
#define VGA_CONSOLE_H

#include <stdint.h>
#include "xparameters.h"

const uint32_t CONS_BASE = XPAR_VGA_CONSOLE_0_S_AXI_BASEADDR;

#define CONS_CTRL  *((uint32_t*) CONS_BASE + 0x0) // Ctrl
#define CURS_LOC   *((uint32_t*) CONS_BASE + 0x4) // Cursor location
#define CHAR_SET   *((uint32_t*) CONS_BASE + 0x8) // Character
#define CHAR_COLOR *((uint32_t*) CONS_BASE + 0xC) // Character color
#define BACK_COLOR *((uint32_t*) CONS_BASE + 0x0) // Background color


struct Point
    { int x, y; };

enum Color
{
    BLACK = 0x000,
    WHITE = 0xFFF,
    RED   = 0xF00,
    GREEN = 0x0F0,
    BLUE  = 0x00F
};

class VGA_Console
{
public:
    VGA_Console(void);
    void en(void);
    void dis(void);

    void clr_line(void);
    void clr_screen(void);

    void putc(char ch);         // Prints character
    void puts(const char* str); // Prints string

    void set_cursor(int x, int y);
    void set_cursor(Point point);
    Point get_cursor(void);

    void set_char_color(Color color);
    void set_back_color(Color color);

    void set_margin(int x, int y);

private:
    const int HEIGHT = 45;
    const int WIDTH  = 80;

    bool displayEn;
    Point cursor, margin;
    Color charColor, backColor;

private:
    void set_w_en(bool w_en); // Sets w_en bit of console control register
    void write_char(char ch); // Sets character register
    void inc_cursor(void);    // Increments cursor
    void endl(void);          // Advances to new line
};


#endif // VGA_CONSOLE_H
