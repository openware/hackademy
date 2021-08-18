#include <stdlib.h>

int my_strlen(const char *restrict s)
{
    int len = 0;
    while (*s++)
    {
        len++;
    }
    return len;
}

char *ft_strmap(const char *s, char (*f)(char))
{
    int len = my_strlen(s);
    char *str = (char *)malloc(len + 1);
    while (*s != '\0')
        *str++ = (*f)(*s++);
    *str = '\0';
    return str - len;
}