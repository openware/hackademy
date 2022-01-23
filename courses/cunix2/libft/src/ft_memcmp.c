#include "../libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *tmp_s1 = s1, *tmp_s2 = s2;
    for (size_t i = 0; i < n; i++)
    {
        if (tmp_s1[i] != tmp_s2[i])
        {
            return tmp_s1[i] - tmp_s2[i];
        }
    }
    return 0;
}