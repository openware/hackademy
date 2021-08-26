/*
 * =====================================================================================
 *
 *       Filename:  ft_memccpy.c
 *
 *    Description:  memccpy lib implementation, which opies no more than n bytes from memory area src to memory area dest, stopping when the character c is found. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 04:56:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

void *ft_memccpy(void *restrict dest, const void *restrict src, int c, size_t n)
{
    unsigned char *dest_pos = (unsigned char *) dest;
    unsigned char *src_pos = (unsigned char *) src;
    
    c %= 256;

    while (n-- != 0)
    {
        *dest_pos++ = *src_pos;

        if (*src_pos == c)
        {
            return (void *) dest_pos;
        }

        src_pos++;
    }

    return 0;
}
