#include <stddef.h>
#include <stdio.h>

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    unsigned char *dest_pos = (unsigned char *) dest;
    unsigned char *src_pos = (unsigned char *) src;

    while (n-- != 0)
    {
        *dest_pos++ = *src_pos++;
    }

    return dest;
}
