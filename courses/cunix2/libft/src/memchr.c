#include <stddef.h>

void *ft_memchr(void *str, int c, unsigned long int n)
{
    while (n--)
    {
        if (*(char *)str == (char)c)
        {
            return str;
        }
        str++;
    }
    return 0;
}