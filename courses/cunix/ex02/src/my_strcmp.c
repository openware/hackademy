#include <stdio.h>
#include <string.h>

int my_strcmp(char *strg1, char *strg2)
{
    while ((*strg1 != '\0' && *strg2 != '\0') && *strg1 == *strg2)
    {
        strg1++;
        strg2++;
    }
    if (*strg1 == *strg2)
    {
        return 0;
    }
    else
    {
        return *strg1 - *strg2;
    }
}