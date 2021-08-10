/*
 * =====================================================================================
 *
 *       Filename:  ft_memcpy.c
 *
 *    Description:  Copies given number of bytes from one memory area to temporary and
 *                  from temporery to another one
 *
 *        Version:  1.0
 *        Created:  08/10/2021 01:41:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *dest_bytes = (unsigned char *) dest;
    unsigned char *middle_bytes = (unsigned char *) malloc(sizeof(unsigned char) * n);
    unsigned char *src_bytes = (unsigned char *) src;

    size_t r = n;
    while (n-- != 0)
    {
        *middle_bytes++ = *src_bytes++;
    }
    n = r;
    
    middle_bytes -= r;
    while (n-- != 0)
    {
        *dest_bytes++ = *middle_bytes++;
    }
    
    free(middle_bytes - r);
    return dest;
}
