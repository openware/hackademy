#include <stdio.h>
int ft_isalpha(int c);
int ft_islower(int c);
int ft_isupper(int c);
int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}
int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}
int ft_isalpha(int c)
{
    return(ft_islower(c) || ft_isupper(c));
}
