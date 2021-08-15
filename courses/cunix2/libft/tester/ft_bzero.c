#include <stdio.h>
void ft_bzero(void *s, size_t n);
void ft_bzero(void *s, size_t n)
{
    size_t i = 0;
    unsigned char *a;
    a = (unsigned char *)s;
    while (i < n)
    {
        a[i] = 0;
        i++;
    }
}
