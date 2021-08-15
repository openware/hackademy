#include <stdio.h>
char *ft_strrchr(const char *s, int c);
unsigned int my_strlen(const char *str);
unsigned int my_strlen(const char *str)
{
    unsigned int length = 0;
    while(*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
char *ft_strrchr(const char *s, int c)
{
    unsigned int len;
    len = my_strlen(s);
    if ((char)c == '\0')
        return ((char)*s + len);
    while (len--)
        if (*(s + len) == c)
            return ((char *)(s + len));
    return (0);
}
