/*
 * =====================================================================================
 *
 *       Filename:  ft_memchr.c
 *
 *    Description:  memchr lib implementation, which scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 05:16:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    c %= 256;

    unsigned char *s_pos = (unsigned char *) s;

    while (n-- != 0)
    {
        if (*s_pos++ == c)
        {
            return (void *)(s_pos - 1);
        }
    }

    return 0;
}
