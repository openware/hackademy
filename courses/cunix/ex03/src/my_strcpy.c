#include <stdio.h>
#include <test.h>

char *my_strcpy(char *dest, const char *src)
{
    char *begin = dest;
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return begin;
}