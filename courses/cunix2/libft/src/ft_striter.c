#include "../libft.h"

void ft_striter(char *str, void (*fn)(char *))
{
    while (*str)
    {
        (*fn)(str++);
    }
}