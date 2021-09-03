#include <stdio.h>
#include "test.h"

unsigned int my_strlen (char *str)
{
    unsigned int letters_count = 0;

    while (*str != '\0')
    {
        str++;
        letters_count++;
    }
    return letters_count;
}
