#include <stdio.h>
#include <string.h>


int my_atoi(const char *nptr)
{
    int number = 0;
    int sign = 1;
    int i = 0;

    if (nptr[i] == '-')
    {
        sign = -1;
        i++;
    }

    while(nptr[i] >= '0' && nptr[i] <= '9'){
        number = number * 10 + nptr[i] - '0';
        i++;
    }

    return sign * number;
}