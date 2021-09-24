#include <stdio.h> //for NULL


void *ft_memchr(void *buf, int ch, int length)
{
    unsigned char *p = (unsigned char *)buf;
    unsigned char *isCharFind = NULL;
    while ((buf != NULL) && (length--))
    {
        if (*p != (unsigned char)ch)
        {
            p++;
        }
        else
        {
            isCharFind = p;
            break;
        }
    }
    return isCharFind;

}