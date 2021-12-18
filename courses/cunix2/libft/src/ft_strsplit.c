#include "../libft.h"

static size_t ft_count_words(const char *s, char c)
{
    size_t words;
    size_t i;

    words = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if ((i == 0 || s[i - 1] == c) && s[i] != c)
        {
            words++;
        }
        i++;
    }
    return (words);
}

static size_t ft_wordlen(char const *s, char c)
{
    size_t i;

    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            s++;
            i++;
        }
        else
        {
            return (i);
        }
    }
    return (i);
}

char *ft_strncpy(char *dst, char const *src, size_t n)
{
    size_t i;

    i = -1;
    if (dst == NULL || src == NULL)
    {
        return (NULL);
    }
    while (++i < n && src[i])
    {
        dst[i] = src[i];
    }
    while (i < n--)
    {
        dst[i] = '\0';
    }
    return (dst);
}

char **ft_strsplit(char const *s, char c)
{
    char **word_tab;
    size_t nb_words;
    size_t word_len;
    size_t i;
    size_t n;

    i = 0;
    n = 0;
    nb_words = ft_count_words(s, c);
    word_tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
    while (n < nb_words && word_tab)
    {
        while (s[i] != '\0' && s[i] == c)
        {
            i++;
        }
        word_len = ft_wordlen(&s[i], c);
        word_tab[n] = malloc(sizeof(**word_tab) * (word_len + 1));
        ft_strncpy(word_tab[n], &s[i], word_len);
        word_tab[n][word_len] = '\0';
        while (s[i] != '\0' && s[i] != c)
        {
            i++;
        }
        n++;
    }
    word_tab[n] = NULL;
    return (word_tab);
}