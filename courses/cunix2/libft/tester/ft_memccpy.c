#include <stdio.h>
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    size_t i = 0;
    unsigned char *pdest;
    unsigned char *psrc;

    pdest = (unsigned char*)dest;
    psrc = (unsigned char*)src;
    while (i < n)
    {
        pdest[i] = psrc[i];
        if (pdest[i] == (unsigned char)c)
            return ((void*)(dest + i + 1));
     }
    return (0);

}
