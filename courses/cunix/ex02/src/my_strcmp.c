#include "test.h"

/* 
compare two strings
return <0 if str1<str2, 0 if str1==str2, >0 if str1>str2
*/
int my_strcmp(char *str1, char *str2) 
{
    for (; *str1 == *str2; str1++, str2++) 
    {
        if (*str1 == '\0')
        {
            return 0;
        }
    }
    return (*str1 - *str2 < 0) ? -1 : 1;
}
