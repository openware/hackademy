#include <stdlib.h>
#include "../libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t l1 = ft_strlen(s1);
    size_t l2 = ft_strlen(s2);
    size_t concat_l = l1 + l2;

    char *concat = (char *) malloc(sizeof(char) * (concat_l + 1));

    if (!concat)
    {
        return 0;
    }

    while (l1-- != 0)
    {
        *concat++ = *s1++;
    }

    while (l2-- != 0)
    {
        *concat++ = *s2++;
    }

    *concat = '\0';

    return concat - concat_l;
}
