char *ft_strchr(const char *str, int ch)
{
    if (ch >= 256)
    {
        ch %= 256;
    }

    while (*str != '\0')
    {
        if (*str == ch)
        {
            return (char *) str;
        }

        str++;
    }

    return (*str == ch) ? (char *) str : 0;
}
