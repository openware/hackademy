#include <stdio.h>
char  *ft_strjoin(char const *s1, char const *s2);
unsigned int my_strlen(char const *str);
void *malloc(size_t size);
unsigned int my_strlen(char const *str)
{
    unsigned int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
char  *ft_strjoin(char const *s1, char const *s2)
{
    char *dst;
    unsigned int i = 0;
    if (s1 == 0 || s2 == 0)
        return (0);
    dst = (char*)malloc(sizeof(*dst) * (my_strlen(s1) + my_strlen(s2) + 1));
    if (dst == 0)
        return (0);
    while (*s1 != '\0')
        dst[i++] = *s1++;
    while (*s2 != '\0')
        dst[i++] = *s2++;
    dst[i] = '\0';
    return (dst);
}
