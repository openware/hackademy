

int ft_memcmp(char *s1, char *s2, int n)
{
    while (n--)
        if (*s1++ != * s2++)
        {
            return *(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1);
        }
    return 0;
}







