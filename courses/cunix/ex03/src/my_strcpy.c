#include "test.h"

/* copy a string `src` to `dest` */
char *my_strcpy(char *dest, const char *src)
{
    unsigned int i = 0;

    for (; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';
    return dest;
}
