#include <stdio.h>
char *ft_strchr(const char *s, int c);
char *ft_strchr(const char *s, int c)
{
    char *p;
    p =(char *s)p;

    while (*p != c)
    {
        if(*p == '\0')
            return (0);
        p++;
    }
    return (p);
}
