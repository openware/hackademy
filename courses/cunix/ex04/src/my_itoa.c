#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int get_digit_count (int nmb)
{
    int count = -1;
    for (;nmb != 0; count++, nmb /= 10)
    {}
    return count;
}

char *my_itoa (int nmb)
{
    int digits = get_digit_count(nmb) + 1;
    char *conv_nmb;
    if (nmb < 0)
    {
        conv_nmb = (char *)malloc(digits + 1);
        digits++;
        *conv_nmb = '-';
        nmb *= -1;
    }
    else if (nmb == 0)
    {
        conv_nmb = (char *)malloc(2);
        conv_nmb[0] = '0';
        conv_nmb[1] = '\0';
        return conv_nmb;
    }
    else
    {
        conv_nmb = (char *)malloc(digits);
    }

    conv_nmb[digits] = '\0';
    for (; nmb != 0; digits--, nmb /= 10)
    {
        conv_nmb[digits - 1] = nmb % 10 + '0';
    }
    return conv_nmb;
}

