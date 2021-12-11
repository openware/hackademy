#include <stdlib.h>
#include <string.h>
#include "test.h"

char *my_strcpy ( char *dest, const char *src){

    int index; // initializing string index

    /* Looping over 'src' string and copying content to 'dest' string 
    untill the index is equal to length of src string*/
    for ( index = 0; index <= (int) strlen(src); index++ ){
        dest[index] = src[index];
    }
    // Returning copy of src
    return dest;
}
