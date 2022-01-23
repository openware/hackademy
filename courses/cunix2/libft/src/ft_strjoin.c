#include "../libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    char *tmp;
    if (!(tmp = (char *)malloc(my_strlen((char *)s1) + my_strlen((char *)s2) + 1)))
    {
        return NULL;
    }
    size_t i = 0;
    for (int j = 0; s1[j]; j++)
    {
        tmp[i++] = s1[j];
    }
    for (int j = 0; s2[j]; j++)
    {
        tmp[i++] = s2[j];
    }
    tmp[i] = '\0';
    return tmp;
}
