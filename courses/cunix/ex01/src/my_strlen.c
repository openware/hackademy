#include "../include/test.h"

/* calculate the length of a string */
unsigned int my_strlen(char *str)
{
    unsigned int char_counter = 0;
    unsigned int pos = 0;

    while (str[pos++] != '\0')
    {
        char_counter++;
    }

    return char_counter;
}
