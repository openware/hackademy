#include <stdlib.h>

char *my_itoa(int nmb)
{

    char *newnumber = (char *)malloc(sizeof(32));
    char *numb = newnumber;
    int sign;
    int length = 0;

    if ((sign = nmb) < 0)
    {
        nmb = -nmb;
    }

    do 
    {
        *newnumber++ = nmb % 10 + '0';
        length++;
    } 
    while ((nmb /= 10) > 0);

    if (sign < 0) 
    {
        length++;
        *newnumber++ = '-';
    }
    *newnumber = '\0';


    for (int i = 0; i < length / 2; i++)
    {
        char c;
        c = numb[i];
        numb[i] = numb[length - i - 1];
        numb[length - i - 1] = c;
    }

    return numb;
}


