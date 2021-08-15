#include <stdio.h>
void *ft_memset(void *s, int c, size_t n);
void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p;
    unsigned char number;
    
    p = (unsigned char *)s;
    number = (unsigned char)c;
    while(n--)
        *p++ = number;
    return (s);
}
