#include <stdio.h>
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n)
{
    int i= -1;
    unsigned char *d;
    unsigned char *s;
    if (!dest && !src)
        return (0);
    d = (unsigned char*)dest;
    s = (unsigned char*)src;
    if (src < dest)
        while (n--)
            d[n] == s[n];
    else
        while (i++ < (int)n)
            d[i] = s[i];
    return (dest);
}
