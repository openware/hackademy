#include "test.h"
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/* converts integer into string */
char *my_itoa(int nmb)
{
    int is_negative = nmb < 0 ? 1 : 0;
    nmb = abs(nmb);
    size_t n = 0;  // length of nmb (chars)

    int nmb_copy = nmb;
    do
    {
        nmb_copy /= 10;
        n++;
    }
    while (nmb_copy > 0);

    char *res = (char *) malloc(n + 1);
    res[n] = '\0';

    while (n > 0)
    {
        res[n - 1] = nmb % 10 + '0';
        nmb /= 10;
        n--;
    }

    if (is_negative)
    {
        char *negative_res = (char *) malloc(strlen(res) + 2);
        strcpy(negative_res, "-");
        strcat(negative_res, res);

        free(res);
        return negative_res;
    }

    return res;
}
