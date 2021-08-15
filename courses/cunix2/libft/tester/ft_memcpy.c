#include <stdio.h>
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *str1;
    const unsigned char *str2;
    str1 = (unsigned char *)dest;
    str2 = (unsigned char *)src;
    
    if(!dest && !src)
        return (NULL);
    if(dest == src || n == 0)
        return (dest);
    while (n--)
    {
        str1[n] = str2[n];
    }  

    return (dest);
}
