#include "test.h"


int my_pow (int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    int res = base; 
    power--;
    for (;power > 0 ;power--)
    {
        res *= base;
    }
    return res;
}

int get_last_char_index (const char *nptr)
{
    int index = 0;
    if (*nptr == '-')
    {
        ++index;
    }
    for (; *(nptr + index) != '\0' && *(nptr + index) <= 57 && *(nptr + index) >= 48; index++) 
    {}
    return --index;
}

int my_atoi (const char *nptr)
{
    if ((*nptr > 57 || *nptr < 48) && *nptr != '-')
    {
        return 0;
    }

    int last_char = get_last_char_index(nptr);
    unsigned int res = 0;
    int mul = 1;
    
    for ( int i = 0;; i++, last_char--) 
    {
        if (*(nptr + i) == '-')
        {
            mul = -1;
            continue;
        }
        unsigned int num = *(nptr + i) - '0';
        res += num * (unsigned int)(my_pow(10,last_char));

        if (last_char == 0) 
        {
            break;
        }
    }

    return res * mul;
}

