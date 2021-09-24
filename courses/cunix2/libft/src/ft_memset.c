//#include "libft.h"

void *ft_memset(void *dst, int c, unsigned int len)
{
    
    unsigned char *p = dst;
    while (len--)
    {
        *p++ = (unsigned char)c;
    }
    return dst;

}