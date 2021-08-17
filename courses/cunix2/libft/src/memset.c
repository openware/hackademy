void *ft_memset(void *str, int c, unsigned long long n)
{
    for (char *s = str; *s != '\0' || n--;)
    {
        *s++ = c;
    }
    return str;
}