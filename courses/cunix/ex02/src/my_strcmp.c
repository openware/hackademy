#include <stdio.h>
#include <string.h>

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    int result = 0;
    while(str1[i] != '\0')
    {
        if(str1[i] > str2[i])
        {
            result = 1;
            break;
        } else if(str1[i] < str2[i])
        {
            result = -1;
        }
        i++;
    }
    return result;
}