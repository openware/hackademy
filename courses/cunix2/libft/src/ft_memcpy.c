#include "../libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char *tmp_dest = dest;
    const char *tmp_src = src;
    for (size_t i = 0; i < n; i++)
    {
        *tmp_dest++ = *tmp_src++;
    }
    return dest;
}