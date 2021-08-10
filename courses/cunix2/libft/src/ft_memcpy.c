/*
 * =====================================================================================
 *
 *       Filename:  ft_memcpy.c
 *
 *    Description:  Copies given number of bytes from one memory area to another 
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

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_bytes = (unsigned char *) dest;
    unsigned char *src_bytes = (unsigned char *) src;

    while (n-- != 0)
    {
        *dest_bytes++ = *src_bytes++;
    }

    return dest;
}
