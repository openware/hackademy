/*
 * =====================================================================================
 *
 *       Filename:  ft_memcmp.c
 *
 *    Description:  Compares given memory areas 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 03:45:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *s1_bytes = (unsigned char *) s1;
    unsigned char *s2_bytes = (unsigned char *) s2;
    int difference;

    while (n-- != 0)
    {
        difference = *s1_bytes++ - *s2_bytes++;

        if (difference > 0)
        {
            return 1;
        }
        else if (difference < 0)
        {
            return -1;
        }
    }

    return 0;
}
