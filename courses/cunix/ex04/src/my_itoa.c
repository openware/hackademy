#include <stdlib.h>

char *my_itoa(int nmb)
{

    char *res = (char *)malloc(40);
    char *numb = res;
    int s;
    int l = 0;

    if ((s = nmb) < 0)
    {
        nmb = -nmb;
    }

    do 
    {
        *res++ = nmb % 10 + '0';
        l++;
    } 
    while ((nmb /= 10) > 0);

    if (s < 0) 
    {
        l++;
        *res++ = '-';
    }
    *res = '\0';
    
    for (int i = 0; i < l / 2; i++)
    {
        char tmp;
        tmp = numb[i];
        numb[i] = numb[l - i - 1];
        numb[l - i - 1] = tmp;
    }

    return numb;
}


