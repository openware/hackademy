#include "../libft.h"

size_t ft_strclen(const char *s, char c)
{
    char *word_end = ft_strchr(s, c);

    if (!word_end)
    {
        return ft_strlen(s);
    }

    return word_end - s;
}
