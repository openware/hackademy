#define NULL 0L

#include <stdlib.h>

int wspace(char c) 
{
    return (c == ' ' || c == '\t' || c == '\n');
}
size_t strspn(const char *s, const char *accept);
int unsigned my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        ++i;
    }
    return i; 
}

int get_first_position(char const *s)
{
    int i = 0;
    while (wspace(s[i])) 
    {
        i += 1;
    }
    return (i);
}

int get_last_position(char const *s)
{
    int i = my_strlen(s) - 1;
    while (wspace(s[i])) 
    {
        i -= 1;
    }
    return (i);
}
int get_trim_len(char const *s)
{
    return (get_last_position(s) - get_first_position(s));
}

char *ft_strtrim(char const *s)
{
    char *trim = NULL;
    int i, len, start;
    if (my_strlen(s) == strspn(s, " "))
    {
        char *l = "";
        l  = (char *)malloc(my_strlen(l));
        return l;
    }
    if (s != NULL) 
    {
        i = 0;
        len = get_trim_len(s) + 1;
        trim = (char *)malloc(len);
        start = get_first_position(s);
        while (i < len) 
        {
            trim[i] = s[start];
            i += 1;
            start += 1;
        }
        trim[i] = '\0';
    }
    return (trim);
}