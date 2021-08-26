/*
 * =====================================================================================
 *
 *       Filename:  ft_memcmp.c
 *
 *    Description:  memcpy lib implementation, which compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 05:30:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *s1_pos = (unsigned char *) s1;
    unsigned char *s2_pos = (unsigned char *) s2;
    int diff;

    while (n-- != 0)
    {
        diff = *s1_pos++ - *s2_pos++;

        if (diff != 0)
        {
            return diff;
        }
    }

    return 0;
}
