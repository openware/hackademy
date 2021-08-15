#include <stdio.h>
char *  ft_strsub(char const *s, unsigned int start, size_t len);
void *malloc (size_t size);
unsigned int my_strlen(char *str);
unsigned int my_strlen(char *str)
{
    unsigned int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
char *  ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t i = 0;
    if (s == 0)
        return (0);
    if (start > my_strlen(s))
        return (0);
    if ((res = (char *)malloc(sizeof(char) * (len+1))) == NULL)
        return (0);
    while(i < len && s[start] != '\0')
    {
        res[i] = s[start];
        start++;
        i++;
    }
    res[i] = '\0';
    return (res);

}
