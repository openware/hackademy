#include <stdlib.h>

unsigned int my_strlen(const char *restrict s)
{
    int len = 0;
    while (*s++)
    {
        len++;
    }
    return len;
}

char *ft_strsub(const char *restrict s, unsigned int start, unsigned long len)
{
    if (s == NULL)
        return NULL;

    unsigned int str_len = my_strlen(s);

    if (str_len < start + len)
        len = str_len - start;
    if (str_len < start)
        len = 0;

    char *str = (char *)malloc(len + 1);
    for (unsigned int i = 0; i < len; i++)
    {
        str[i] = s[start + i];
    }
    str[len] = '\0';
    return str;
}