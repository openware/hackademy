#include <stdio.h>
int my_strcmp(char *str1, char *str2);

int my_strcmp(char *str1, char *str2)
{
    while((*str1 == *str2) && (str1 != '\0' || str2 != '\0'))
    {
        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0')
        return 0;
    else
        return -1;
}
