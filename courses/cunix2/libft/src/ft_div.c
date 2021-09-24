
#include "../libft.h"



div_t ft_div(numer, denom)int numer, denom;
{
    div_t result;

    result.quot = numer / denom;
    result.rem = numer % denom;

    if (numer >= 0 && result.rem < 0)
    {
        ++result.quot;
        result.rem -= denom;
    }

    return result;
}

