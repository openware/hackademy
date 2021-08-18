#include <stdlib.h>

#include "../libft.h"

char *ft_strtrim(const char *s)
{

    if (s == NULL)
        return NULL;

    while (*s == '\n' || *s == '\t' || *s == ' ')
        s++;

    const char *str = s;
    while (*(s + 1) != '\0')
        s++;
    
    while (*s == '\n' || *s == '\t' || *s == ' ')
        s--;

    return ft_strsub(str, 0, s - str + 1);
}