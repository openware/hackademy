#include "../libft.h"

int ft_isascii(int chr)
{
    return (chr >= 0) ? chr == (char)chr : 0;
}