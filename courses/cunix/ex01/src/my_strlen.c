#include <stdio.h>
#include <string.h>

unsigned int my_strlen(char *str)
{
    unsigned int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}
