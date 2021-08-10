/*
 * =====================================================================================
 *
 *       Filename:  ft_memset.c
 *
 *    Description:  Fills first bytes of given length with the given constant 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 01:30:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *s_bytes = (unsigned char *) s;

    while (n-- != 0)
    {
        *s_bytes++ = (unsigned char) c;
    }

    return s;
}
