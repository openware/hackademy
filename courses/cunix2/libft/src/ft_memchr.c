/*
 * =====================================================================================
 *
 *       Filename:  ft_memchr.c
 *
 *    Description:  Finds first occurence of character in given memory area 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 03:36:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *s_bytes = (unsigned char *) s;
    while (n-- != 0)
    {
        if (*s_bytes++ == c % 256)
        {
            return (s_bytes - 1);
        }
    }
    return 0;
}
