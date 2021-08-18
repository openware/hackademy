#include <stdio.h>
#include <stdlib.h>

unsigned int my_strlen(const char *restrict s)
{
    int len = 0;
    while (*s++)
    {
        len++;
    }
    return len;
}

char *ft_strjoin(const char *s1, const char *s2) {
    unsigned len1 = my_strlen(s1);
    unsigned len2 = my_strlen(s2);
    char *str = (char *)malloc(len1 + len2 + 1);
    for (unsigned int i = 0; i < len1; i++) {
        str[i] = s1[i];
    }
    for (unsigned int i = 0; i < len2; i++) {
        str[len1 + i] = s2[i];
    }
    str[len1 + len2] = '\0';
    return str;
}