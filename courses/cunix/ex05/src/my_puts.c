#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int my_puts(const char *s){
    while ( *s != '\0'){ // Writing till terminating null character(end of string)
        write(1, &*s++, sizeof(char));
    }
    write(1, &"\n", sizeof(char)); // Writing next line after end of the string
    return 0;
}
