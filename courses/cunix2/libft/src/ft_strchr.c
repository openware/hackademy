/*
 * =====================================================================================
 *
 *       Filename:  ft_strchr.c
 *
 *    Description:  strchr lib implementation, which returns  a pointer to the first occurrence of the character c in the string s.
 *
 *        Version:  1.0
 *        Created:  08/25/2021 07:33:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
    c %= 256;

    while (*s != '\0')
    {
        if (*s == c)
        {
            return (char *) s;
        }

        s++;
    }

    return (*s == c) ? (char *) s : 0;
}
