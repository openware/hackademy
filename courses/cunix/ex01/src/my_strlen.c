#include <stdio.h>
#include "test.h"

// function for calculating  length of a string 
unsigned int my_strlen(char *str)
{
    // declaring index beginning of string
    unsigned int char_index = 0;

    /* Looping over the string and incrementing index untill terminating
    null character found */
    while (str[char_index] != '\0')
    {
        char_index++;
    }

    return char_index;
}
