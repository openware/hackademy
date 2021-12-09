#include <stdio.h>
unsigned int my_strlen(char *str)
{
    int counter = 0;
    while(str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}
