
#include "VGA_Console.h"

VGA_Console::VGA_Console(void)
{
    CONS_CTRL = 0;
    CHAR_SET  = 0;

    // clr_screen();

    set_cursor(8, 4);
    set_margin(8, 4);

    set_char_color(WHITE);
    set_back_color(BLACK);
    en();
}

void VGA_Console::en(void)
    { CONS_CTRL |= 0b1; }

void VGA_Console::dis(void)
    { CONS_CTRL &= ~0b1; }

void VGA_Console::clr_line(void)
{
    for (int i = margin.x; i <= WIDTH - margin.x; i++)
    {
        set_cursor(i, cursor.y);
        putc('\0');
    }
    set_cursor(margin.x, cursor.y);
}

void VGA_Console::clr_screen(void)
{
    for (int i = margin.y; i <= HEIGHT - margin.y; i++)
    {
        set_cursor(0, i);
        clr_line();
    }
    set_cursor(margin.x, margin.y);
}

void VGA_Console::putc(char ch)
{
    if (ch == 0x12 || ch == 0x15)
        endl();

    set_w_en(false);
    write_char(ch);
    set_w_en(true);
    // wait for resp?
    set_w_en(false);
    inc_cursor();
}

void VGA_Console::puts(const char* str)
{
    int i = 0;
    while (1)
    {
        if (str[i] == '\0' || i == 50)
            return;
        else
            putc(str[i]);
        
        i++;
    }
}

void VGA_Console::endl(void)
{
    if (cursor.y == (HEIGHT - margin.y))
        return;
    else
        cursor.y++;
}

void VGA_Console::set_cursor(int x, int y)
{
    if ((1 <= x && x <= WIDTH)
     && (1 <= y && y <= HEIGHT))
    {
        CURS_LOC = ((x - 1) & 0xFFF);
        CURS_LOC <<= 12;
        CURS_LOC |= ((y - 1) & 0xFFF);

        cursor = { x, y };
    }
}

void VGA_Console::set_cursor(Point point)
    { set_cursor(point.x, point.y); }

Point VGA_Console::get_cursor(void)
    { return cursor; }

void VGA_Console::set_char_color(Color color)
    { CHAR_COLOR = (uint16_t)color; }

void VGA_Console::set_back_color(Color color)
    { BACK_COLOR = (uint16_t)color; }

void VGA_Console::set_margin(int x, int y)
{
    if (0 <= x && x <= WIDTH / 2)
        margin.x = x;
    if (0 <= y && y <= HEIGHT / 2)
        margin.y = y;
}

void VGA_Console::set_w_en(bool w_en)
    { CONS_CTRL |= ((uint8_t)w_en << 1); }

void VGA_Console::write_char(char ch)
    { CHAR_SET = ch; }

void VGA_Console::inc_cursor(void)
{
    if (cursor.x == (WIDTH - margin.y))
    {
        if (cursor.y == (HEIGHT - margin.x))
            return;
        else
        {
            cursor.y++;
            cursor.x = margin.x + 1;
        }
    }
    else
        cursor.x++;
}
