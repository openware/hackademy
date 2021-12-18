#include "../libft.h"

char *ft_strtrim(const char *str)
{
    while (*str && (*str == ' ' || *str == ',' || *str == '\n' || *str == '\t'))
    {
        str++;
    }
    const char *tmp = str + my_strlen((char *)str);
    while (tmp > str && (*(tmp - 1) == ' ' || *(tmp - 1) == ',' || *(tmp - 1) == '\n' || *(tmp - 1) == '\t'))
    {
        tmp--;
    }

    char *cutted;
    if (!(cutted = (char *)malloc(tmp - str + 1)))
    {
        return NULL;
    }
    size_t i;
    for (i = 0; str + i < tmp; i++)
    {
        cutted[i] = str[i];
    }
    cutted[i] = '\0';
    return cutted;
}