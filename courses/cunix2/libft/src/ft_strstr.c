char *ft_strstr(const char *haystack, const char *needle)
{
    if (*haystack == '\0')
    {
        return (char *) needle;
    }

    if (*needle == '\0')
    {
        return (char *) haystack;
    }

    char *h_pos;
    char *n_pos;
    int found = 0;

    while (*haystack != '\0')
    {
        h_pos = (char *) haystack;
        n_pos = (char *) needle;

        while (*n_pos != '\0')
        {
            if (*h_pos++ == *n_pos++)
            {
                found = 1;
            }
            else
            {
                found = 0;
                break;
            }
        }

        if (found)
        {
            return (char *) haystack;
        }

        haystack++;
    }

    return 0;
}
