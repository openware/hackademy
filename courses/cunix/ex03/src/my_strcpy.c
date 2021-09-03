#include "test.h"

char *my_strcpy (char *dest, const char *src)
{
    for (int i = 0,j = 0;; i++,j++)
    {
        *(dest + j) = *(src + i);
        if (*(src + i) == '\0')
        {
            break;
        }
    }
    return dest;
}
