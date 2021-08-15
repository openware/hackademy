#include <stdio.h>
int ft_memcmp(const void *s1, const void *s2, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *p1;
    unsigned char *p2;
    size_t i = 0;
    p1 = (unsigned char *)s1;
    p2 = (unsigned char *)s2;
    while (*p1 == *p2 && n > i++)
    {
        p1++;
        p2++;
    }

    return (*p1 - *p2);
}
