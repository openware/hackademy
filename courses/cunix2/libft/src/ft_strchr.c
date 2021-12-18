#include "../libft.h"

char *ft_strchr(const char *s, int c)
{
    c = (char)c;
    do
    {
        if (*s == c)
        {
            return (char *)s;
        }
    } while (*s++);
    return NULL;
}