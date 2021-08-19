
char *my_strcpy(char *dest, const char *src) 
{
    char *res = dest;

    while ((*dest++ = *src++));

    return res;
}
