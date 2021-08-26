/*
 * =====================================================================================
 *
 *       Filename:  ft_memcpy.c
 *
 *    Description:  memcpy lib implementation, which opies n bytes from memory area src to memory area dest. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 02:03:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>
#include <stdio.h>

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    unsigned char *dest_pos = (unsigned char *) dest;
    unsigned char *src_pos = (unsigned char *) src;

    while (n-- != 0)
    {
        *dest_pos++ = *src_pos++;
    }
    
    return dest;
}
