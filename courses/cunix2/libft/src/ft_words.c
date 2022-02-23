
unsigned int ft_words(const char *s, char c)
{
    unsigned int num_words = 0;

    while (*s != '\0')
    {
        while (*s == c && *s != '\0')
        {
            s++;
        }

        if (*s != '\0')
        {
            num_words++;

            while (*s != c && *s != '\0')
            {
                s++;
            }
        }
    }

    return num_words;
}
