#include <stdio.h>
char *  ft_strtrim(char const *s);
void *malloc (size_t size);
unsigned int my_strlen(char *str);
int ft_isspace(int c);
int ft_isspace(int c)
{
    return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}
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
char * ft_strsub(char const *s, unsigned int start, size_t len);
char * ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t i = 0;
    if (s ==0)
        return (0);
    if (start > my_strlen(s))
        return (0);
    if ((res = (char *)malloc(sizeof(char) * (len+1))) == NULL)
        return (0);
    while (i < len && s[start] != '\0')
    {
        res[i] = s[start];
        start++;
        i++;
    }
    res[i] = '\0';
    return (res);
}
char *  ft_strtrim(char const *s)
{
   size_t l;
   size_t i = 0;
   char *r;
   if (!s)
       return (0);
   while (ft_isspace(s[i]))
       i++;
   l = my_strlen((char *)s);
   while(ft_isspace(s[l - 1]) && l > i)
       l--;
   r = ft_strsub(s, i, l - i);
   return (r);
}
