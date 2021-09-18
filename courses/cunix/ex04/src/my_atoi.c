
#include <stdlib.h>
#include <assert.h>
#include "test.h"

int my_atoi(const char *nptr){
  
    int i = 0;
    int minus = 1;
    int val = 0;
    while (nptr[i] == '-') {
        minus = -minus;
        i++;
    }
    while(nptr[i] >= '0' && nptr[i] <= '9')
    {
        int nbr = (int) (nptr[i] - '0');

        val = (val * 10) + nbr;
        i++;
    }
    return val*minus;
   
}