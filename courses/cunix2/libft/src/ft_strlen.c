#include <stddef.h>

size_t ft_strlen(const char *s)
{
    size_t len = 0;

    while (*s++ != '\0')
    {
        len++;
    }

    return len;
}
