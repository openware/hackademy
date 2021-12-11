#include <stdlib.h>
#include "test.h"


int my_atoi(const char *nptr){  
    int index = nptr[0] == '-' ? 1: 0;
    int integer = 0;


    while (nptr[index] >= '0' || nptr[index] <= '9'){
        integer *= 10;
        integer = (nptr[index] - '0');
        index ++;  
    }

    if (nptr[0] == '-'){
        integer*= -1;
    }

    
    return integer;
}