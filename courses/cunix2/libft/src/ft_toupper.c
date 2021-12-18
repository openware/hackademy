#include "../libft.h"

int ft_toupper(int chr)
{

    chr = (char)chr;

    if ('a' <= chr && chr <= 'z')
    {
        return chr - ('a' - 'A');
    }
    else
    {
        return chr;
    }
}