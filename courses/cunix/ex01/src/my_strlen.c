#include <stdio.h>
unsigned int my_strlen(char *str);

unsigned int my_strlen(char *str)
{
    unsigned int length = 0;
    while(*str!='\0')
    {
        length++;
        str++;
    }
    return length;
}
