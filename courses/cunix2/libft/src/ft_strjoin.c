#include <stdlib.h>

int ft_strlen(const char *);

char *ft_strjoin(const char *str1, const char *str2)
{
    int l1 = ft_strlen(str1);
    int l2 = ft_strlen(str2);
    int f_l = l1 + l2;

    char *concat = (char *) malloc(sizeof(char) * (f_l + 1));

    while (l1-- != 0)
    {
        *concat++ = *str1++;
    }

    while (l2-- != 0)
    {
        *concat++ = *str2++;
    }

    *concat = '\0';

    return concat- f_l;
}
