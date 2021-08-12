#include <stdio.h>
int my_puts(const char *s);
int my_puts(const char*s)
{
    while (*s)
    {
        if (putchar(*s++) == EOF)
            return EOF;
    }
    if(putchar('\n') == EOF)
        return EOF;
    return 0;
}
