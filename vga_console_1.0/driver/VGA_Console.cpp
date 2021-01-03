
#include "VGA_Console.h"


////////// Public functions //////////

VGA_Console::VGA_Console(void)
{
    disable_write();
    dis();
    CHAR_SET = '\0';

    set_cursor(1, 1);
    set_margin(1, 1);

    set_char_color(Color::WHITE);
    set_back_color(Color::BLACK);
    en();
}

void VGA_Console::en(void)
    { CONS_CTRL |= 0b1; }

void VGA_Console::dis(void)
    { CONS_CTRL &= ~0b1; }

void VGA_Console::putc(char ch)
{
    if (ch == '\n')
        endl();
    else
    {
        write_char(ch);
        inc_cursor();
    }
}

void VGA_Console::puts(const char* str)
{
    int i = 0;

    while (str[i] != '\0')
        putc(str[i++]);
}

void VGA_Console::puti(int num)
{
    char num_str[12];
    itoa(num, num_str, 10);
    puts(num_str);
}

void VGA_Console::endl(void)
{
    if (cursor.y == (HEIGHT - 1 - margin.y)) // Cursor on final line
        return;
    else
        set_cursor(margin.x, cursor.y + 1);
}

void VGA_Console::clr_line(void)
{
    for (int i = 0; i < WIDTH; i++)
    {
        set_cursor(i, cursor.y);
        putc('\0');
    }
    set_cursor(margin.x, cursor.y);
}

void VGA_Console::clr_screen(void)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        set_cursor(0, i);
        clr_line();
    }
    set_cursor(margin);
}

void VGA_Console::set_cursor(Point point)
{
    if ((0 <= point.x && point.x < WIDTH ) && (0 <= point.y && point.y < HEIGHT))
    {
        cursor = point;

        CURS_LOC = (cursor.x & 0xFFF);
        CURS_LOC <<= 12;
        CURS_LOC |= (cursor.y & 0xFFF);
    }
}

void VGA_Console::set_cursor(int x, int y)
    { set_cursor({ x, y }); }

Point VGA_Console::get_cursor(void)
    { return cursor; }

void VGA_Console::set_margin(int x, int y)
{
    if (0 <= x && x < WIDTH / 2)
        margin.x = x;
    if (0 <= y && y < HEIGHT / 2)
        margin.y = y;
}

void VGA_Console::set_char_color(uint16_t color)
    { CHAR_COLOR = (color & 0xFFF); }

void VGA_Console::set_back_color(uint16_t color)
    { BACK_COLOR = (color & 0xFFF); }


////////// Private functions //////////

void VGA_Console::enable_write(void)
    { CONS_CTRL |= (0b1 << 1); }

void VGA_Console::disable_write(void)
    { CONS_CTRL &= ~(0b1 << 1); }

void VGA_Console::write_char(char ch)
{
    CHAR_SET = ch;
    enable_write();
    disable_write();
}

void VGA_Console::inc_cursor(void)
{
    if (cursor.x == (WIDTH - 1 - margin.x))
        endl();
    else
        set_cursor(cursor.x + 1, cursor.y);
}
