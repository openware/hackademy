
#include <stdlib.h>
#include "../libft.h"

char **ft_strsplit(char const *s, char c)
{
    unsigned int num_words = ft_words(s, c);
    char **words = (char **) malloc(sizeof(char *) * (num_words + 1));

    unsigned int curr_word_len;
    char *word = NULL;

    while (*s != '\0')
    {
        while (*s == c && *s != '\0')
        {
            s++;
        }

        if (*s != '\0')
        {
            curr_word_len = ft_strclen(s, c);
            word = (char *) malloc(sizeof(char) * (curr_word_len + 1));

            while (*s != c && *s != '\0')
            {
                *word++ = *s++;
            }

            *word = '\0';
            *words++ = word - curr_word_len;
        }
    }

    *words = NULL;

    return words - num_words;
}
