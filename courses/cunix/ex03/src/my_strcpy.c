char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (*src != '\0')
    {
        dest[i++] = *src++;
    }
    dest[i] = '\0';
    return dest;
}
