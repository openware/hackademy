#include <unistd.h>

int my_puts(const char *s)
{
    while (*s++) 
    {
        write(1, s, 1);
    }

    write(1, "\n", 1);

    return 0;

}


