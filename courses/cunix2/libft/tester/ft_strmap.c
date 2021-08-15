#include <stdio.h>
char  *ft_strmap(char const *s, char (*f)(char));
void *malloc(size_t size);
char  *ft_strmap(char const *s, char (*f)(char))
{
    size_t i = 0;
    char *str;
    if (!*s || !*f)
        return (NULL);
    
    while (s[i])
        i++;
    str = (char *)malloc(sizeof(char) * i + 1);
    if (*s && *str && *f)
    {
        i = 0;
        while (s[i])
        {
            str[i] = f(s[i]);
        }
        return (str);
    }

    return (NULL);
}
