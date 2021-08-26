/*
 * =====================================================================================
 *
 *       Filename:  ft_bzero.c
 *
 *    Description:  Implementation of bzero lib function, which erases the data in the n bytes of the memory, starting at the location pointed to by s, by writing zeros (bytes containing  '\0') to that area. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 02:06:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
    char *data = (char *) s;
    
    while (n-- != 0)
    {
        *data++ = '\0';
    }
}
