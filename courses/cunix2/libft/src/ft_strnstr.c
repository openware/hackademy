#include "../libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t c;
    size_t n_len;
    char *hay;

    i = 0;
    hay = (char *)haystack;
    n_len = my_strlen(needle);
    if (n_len == 0 || haystack == needle)
    {
        return (hay);
    }
    while (hay[i] != '\0' && i < len)
    {
        c = 0;
        while (hay[i + c] != '\0' && needle[c] != '\0' && hay[i + c] == needle[c] && i + c < len)
        {
            c++;
        }
        if (c == n_len)
        {
            return (hay + i);
        }
        i++;
    }
    return (0);
}