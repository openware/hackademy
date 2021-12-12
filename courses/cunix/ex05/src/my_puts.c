#include <string.h>
#include <stdio.h>
#include <unistd.h>

int my_puts(const char *s)
{
    int i = 0;
    while (s[i])
    {
        if (putchar(s[i]) == EOF)
        {
            return EOF;
        }
        i++;
    }
    if (putchar('\n') == EOF)
    {
        return EOF;
    }
    return 1;
}