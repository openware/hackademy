#include <stdio.h>

unsigned int my_strlen(char *str)
{
    int length = 0;
    while (str[length]!='\0')
        length++;
    return length;
}
