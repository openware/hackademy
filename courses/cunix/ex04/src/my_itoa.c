#include "test.h"
#include <malloc.h>
#include <stdlib.h>

char* my_itoa(int nmb)
{
    int is_negative = nmb < 0 ? 1 : 0;
    nmb = abs(nmb);
    int n = 0;  // length of nmb (chars)

    int nmb_copy = nmb;
    do {
        nmb_copy /= 10;
        n++;
    } while (nmb_copy > 0);

    char *res = (char*) malloc(is_negative ? n+1 : n);

    int shift = 0;
    if (is_negative)
    {
        res[0] = '-';
        shift = 1;
    }

    while (n > 0)
    {
        res[n-1+shift] = nmb % 10 + '0';
        nmb /= 10;
        n--;
    }

    return res;
}
