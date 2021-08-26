/*
 * =====================================================================================
 *
 *       Filename:  ft_memmove.c
 *
 *    Description:  memmove lib implementation, which copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.  
 *
 *        Version:  1.0
 *        Created:  08/26/2021 05:05:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *dest_pos = (unsigned char *) dest;
    unsigned char *src_pos = (unsigned char *) src;
    unsigned char *temp_arr = (unsigned char *) malloc(sizeof(unsigned char) * n);

    size_t i = n;

    while (i-- != 0)
    {
        *temp_arr++ = *src_pos++;
    }

    i = n;
    temp_arr -= i;

    while (i-- != 0)
    {
        *dest_pos++ = *temp_arr++;
    }

    free(temp_arr - n);
    return dest;
}
