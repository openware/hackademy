#include <stdio.h>
void *ft_memchr(const void *s, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *p;
    p = (unsigned char *)s;
    while (n--)
    {
        if( (unsigned char)c != *p )
            p++;
        else return (p);
    }
    return (0);
}
