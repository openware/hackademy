
void *ft_memcpy(void *dest, const char *src, unsigned long int n)
{
    char *s = dest;
    while (n--)
    {
        *s++ = *src++;
    }
    return dest;
}