
#ifndef TESTS_H
#define TESTS_H

#include "VGA_Console.h"
#include <time.h>


class Tests
{
private:
    inline static VGA_Console console;

public:
    static void HelloWorld()
    {
        console.set_char_color(Color::GREEN);
        console.puts("Hello World!\n");
    }

    static void Edges()
    {
        console.set_cursor(0, 0);
        console.putc('1');
        
        console.set_cursor(79, 0);
        console.putc('2');
        
        console.set_cursor(0, 44);
        console.putc('3');
        
        console.set_cursor(79, 44);
        console.putc('4');
    }

    static void NewLines()
    {
        console.puts("This is line 1.\n");
        console.puts("This one is line 2.");
        console.endl();
        console.endl();
        console.puts("Final line.");
    }

    static void Overflow()
    {
        console.puts("Line 1");
        console.set_cursor(72, 1);
        console.puts("Text wrapping test.");
        console.endl();
        console.endl();
        console.puts("Second line.");
        console.set_cursor(74, 43);
        console.puts("1234567890");
    }

    static void Colors()
    {
        console.set_back_color(Color::WHITE);

        console.set_char_color(Color::BLACK);
        console.puts("Black\n");
        console.set_char_color(Color::RED);
        console.puts("Red\n");
        console.set_char_color(Color::GREEN);
        console.puts("Green\n");
        console.set_char_color(Color::BLUE);
        console.puts("Blue\n");
    }

    static void FillScreen(char fillChar='E')
    {
        for (int i = 0; i < 45; i++)
            for(int j = 0; j < 80; j++)
            {
                console.set_cursor(j, i);
                console.putc(fillChar);
            }
    }

    static void Clearing()
    {
        console.puts("Hello\n\n");
        console.puts("Goodbye");
        sleep(8);
        console.clr_line();
        console.endl();
        console.endl();
        console.puts("Goodbye");
        sleep(4);
        console.clr_screen();
        console.puts("Goodbye");
    }

    static void Count()
    {
        sleep(4);
        for (int i = 1; i <= 43; i++)
        {
            console.puts("Line: ");
            console.puti(i);
            console.endl();
            sleep(1);
        }
    }

    static void HelloHelloWorld()
    {
        console.puts("#include <stdio.h>\n");
        console.puts("\n");
        console.puts("int main(void)\n");
        console.puts("{\n");
        console.puts("    printf(\"Hello World!\");\n");
        console.puts("\n");
        console.puts("    return 0;\n");
        console.puts("}\n");
    }
};


#endif // TESTS_H
