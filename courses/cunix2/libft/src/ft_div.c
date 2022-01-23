#include "../libft.h"

div_t ft_div(int numer, int denom)
{
    div_t tmp;
    if (!denom)
    {
        tmp.quot = tmp.rem = 0;
        return tmp;
    }
    tmp.quot = numer / denom;
    tmp.rem = numer % denom;
    return tmp;
}