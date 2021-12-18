#include <stdlib.h>
#include "../libft.h"

void ft_bzero(void *s, size_t n)
{
    char *str = s;
    while (n > 0)
    {
        *str++ = '\0';
        n--;
    }
}