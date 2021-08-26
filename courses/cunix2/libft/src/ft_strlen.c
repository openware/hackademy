/*
 * =====================================================================================
 *
 *       Filename:  ft_strlen.c
 *
 *    Description:  strlen lib implementation, which calculates the length of the string given. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 07:16:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

size_t ft_strlen(const char *s)
{
    size_t len = 0;

    while (*s++ != '\0')
    {
        len++;
    }

    return len;
}
