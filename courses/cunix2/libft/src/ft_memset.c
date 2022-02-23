#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *pos = (unsigned char *) s;

    while (n-- != 0)
    {
        *pos++ = (unsigned char) c;
    }

    return s;
}
