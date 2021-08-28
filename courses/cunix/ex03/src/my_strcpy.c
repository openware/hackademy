// copies src data to dest
char *my_strcpy(char *dest, const char *src)
{
    char *destPtr = dest;
    while(*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return destPtr;
}
