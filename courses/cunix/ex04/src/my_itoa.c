#include <stdlib.h>

// converts int to string
char *my_itoa(int nmb)
{
    if (nmb == 0)
    {
        char *str = calloc(2, sizeof(char));
        *str = '0';
        str++;
        *str = '\0';
        return --str;
    } 
    
    unsigned int unsigned_nmb = nmb < 0 ? - nmb : nmb;
    int nmb_length = 0;
    unsigned int nmb_copy = unsigned_nmb; 
    
    while (nmb_copy > 0) // calculate length
    {
        nmb_copy /= 10;
        nmb_length++;
    }
    if (nmb >= 0) // if nmb is positive
    {
        char *str = calloc(nmb_length + 1, sizeof(char)); 
        str[nmb_length] = '\0';
        int i = nmb_length - 1;
        
        while (i >= 0)
        {
            str[i] = (unsigned_nmb % 10) + '0';
            i--;
            unsigned_nmb /= 10;
        }
        
        return str;
    }
    else // if nmb is negative
    {
        char *str = calloc(nmb_length + 2, sizeof(char)); 
        str[nmb_length + 1] = '\0';
        str[0] = '-';
        int i = nmb_length;
        
        while (i >= 1)
        {
            str[i] = (unsigned_nmb % 10) + '0';
            i--;
            unsigned_nmb /= 10;
        }
        
        return str;
    }
}
