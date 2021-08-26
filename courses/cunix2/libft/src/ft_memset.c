/*
 * =====================================================================================
 *
 *       Filename:  ft_memset.c
 *
 *    Description:  memset lib implementation, which fills the first n bytes of the memory area pointed to by s with the constant byte c. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 01:55:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *pos = (unsigned char *) s;

    while (n-- != 0)
    {
        *pos++ = (unsigned char) c;
    }

    return s;
}
