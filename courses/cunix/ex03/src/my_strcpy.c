#include <stdio.h>
char *strcpy(char *dest, const char *src);

char *strcpy(char *dest, const char *src)
{
    char *final = dest;
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = 0;
    return final;
}
