
#ifndef VGA_CONSOLE_H
#define VGA_CONSOLE_H

#include <stdint.h>
#include <stdlib.h>
#include <sleep.h>
#include "xparameters.h"


const uint32_t CONS_BASE = XPAR_VGA_CONSOLE_0_S_AXI_BASEADDR;

#define CONS_CTRL  *((uint32_t*) (CONS_BASE + 0x00)) // Ctrl
#define CURS_LOC   *((uint32_t*) (CONS_BASE + 0x04)) // Cursor location
#define CHAR_SET   *((uint32_t*) (CONS_BASE + 0x08)) // Character
#define CHAR_COLOR *((uint32_t*) (CONS_BASE + 0x0C)) // Character color
#define BACK_COLOR *((uint32_t*) (CONS_BASE + 0x10)) // Background color


struct Point
    { int x, y; };

struct Color
{
    const static uint16_t BLACK = 0x000;
    const static uint16_t WHITE = 0xFFF;
    const static uint16_t RED   = 0xF00;
    const static uint16_t GREEN = 0x0F0;
    const static uint16_t BLUE  = 0x00F;
};


class VGA_Console
{
public:
    VGA_Console(void);
    void en(void);
    void dis(void);

    void putc(char ch);         // Prints character
    void puts(const char* str); // Prints string
    void puti(int num);         // Prints integer
    void endl(void);            // Advances to new line

    void clr_line(void);
    void clr_screen(void);

    void set_cursor(Point point);
    void set_cursor(int x, int y);
    Point get_cursor(void);

    void set_margin(int x, int y);

    void set_char_color(uint16_t color);
    void set_back_color(uint16_t color);

private:
    void enable_write(void);
    void disable_write(void);
    void write_char(char ch); // Writes the character to the cursor position
    void inc_cursor(void);    // Increments cursor

private:
    const int HEIGHT = 45;
    const int WIDTH  = 80;

    Point cursor, margin;
};


#endif // VGA_CONSOLE_H
