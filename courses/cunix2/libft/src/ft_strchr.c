

char *ft_strchr(char *s, int c)
{
    while (*s != (char)c)
    {
        if (!*s++)
        {
            return 0;
        }
    }
    return (char *)s;
}



