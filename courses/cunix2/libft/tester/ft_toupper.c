#include <stdio.h>
int ft_toupper(int c);
int ft_islower(int c);
int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}
int ft_toupper(int c)
{
    if(ft_islower(c))
        return (c - 32);
    return c;
}
