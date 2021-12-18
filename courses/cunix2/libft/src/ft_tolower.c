#include "../libft.h"

int ft_tolower(int chr)
{
    chr = (char)chr;
    return ('A' <= chr && chr <= 'Z') ? chr + ('a' - 'A') : chr;
}