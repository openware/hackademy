#include <stdlib.h>

div_t ft_div(int numerator, int denominator)
{
    div_t res = 
    {
        numerator / denominator,
        numerator % denominator
    };

    return res;
}
