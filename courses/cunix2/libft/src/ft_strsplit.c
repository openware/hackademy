#include <stdlib.h>

char **ft_strsplit(char const *s, char c)
{
    unsigned int words;
    if (s == NULL || *s == 0)
    {
        words = 0;
    }
    else
    {
        while (*s == c)
            s++;

        if (*s != '\0')
        {
            words = 1;
            char const *str = s;
            while (*(str + 1) != '\0')
            {
                if (*str == c && *(str + 1) != c)
                    words++;
                str++;
            }
        }
        else
        {
            words = 0;
        }
    }

    char **result = (char **)malloc(sizeof(char *) * (words + 1));
    for (unsigned int i = 0; i < words; i++)
    {
        unsigned int len = 0;
        char const *str = s;
        while (*str != c && *str != '\0')
        {
            str++;
            len++;
        }
        result[i] = (char *)malloc(len + 1);
        for (unsigned int j = 0; j < len; j++)
        {
            result[i][j] = *s++;
        }
        result[i][len] = '\0';
        while (*s == c)
        {
            s++;
        }
    }
    result[words] = NULL;
    return result;
}