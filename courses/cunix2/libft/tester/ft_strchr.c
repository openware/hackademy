#include <stdio.h>
char *ft_strchr(const char *s, int c);
char *ft_strchr(const char *s, int c)
{
    while ((*s != '\0') && (*s != c))
    {
        s++;
    }
    if (*s == c)
    {
        return ((char *)s);
    }
    return ((char*)NULL);
}
