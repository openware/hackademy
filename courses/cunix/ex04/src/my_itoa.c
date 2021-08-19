#include <stdlib.h>
#define EXP 10

void my_reverse(char *src, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char temp;
        temp = src[i];
        src[i] = src[len - i - 1];
        src[len - i - 1] = temp;
    }
}


char *my_itoa(int nmb)
{
    char *result = (char *)malloc(32);
    char *number = result;
    int len = 0;
    int sign;

    if ((sign = nmb) < 0)
    {
        nmb = -nmb;
    }

    do
    {
        *result++ = nmb % EXP + '0';
        len++;
    }
    while ((nmb /= EXP) > 0);

    if (sign < 0) 
    {
        len++;
        *result++ = '-';
    }

    *result = '\0';
    my_reverse(number, len);

    return number;
}
