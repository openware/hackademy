#include <stdio.h>
int ft_tolower(int c);
int ft_isupper(int c);
int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}
int ft_tolower(int c)
{
    if(ft_isupper(c))
        return (c+32);
    return (c);
}
