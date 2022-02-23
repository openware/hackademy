#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
    c %= 256;

    while (*s != '\0')
    {
        if (*s == c)
        {
            return (char *) s;
        }

        s++;
    }

    return (*s == c) ? (char *) s : 0;
}
