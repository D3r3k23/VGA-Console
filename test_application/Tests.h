
#include "VGA_Console.h"
#include <stdlib.h>
#include <time.h>


class Tests
{
private:
    inline static VGA_Console console;

public:
    static void HelloWorld()
    {
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
};
