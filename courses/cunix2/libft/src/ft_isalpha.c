#include "../libft.h"

int ft_isalpha(int chr)
{
    chr = (char)chr;
    return (('A' <= chr && chr <= 'Z') || ('a' <= chr && chr <= 'z'));
}