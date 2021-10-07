#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int num)
{
    char *str = malloc(0);
    sprintf(str, "%d", num);
    return str;
}
