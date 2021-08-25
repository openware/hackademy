/*
 * =====================================================================================
 *
 *       Filename:  ft_strrchr.c
 *
 *    Description:  strrchr lib implementation, which returns a pointer to the last  occurrence  of  the character c in the string s. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 07:51:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
    c %= 256;

    char *res = NULL;
    while (*s != '\0')
    {
        if (*s == c)
        {
            res = (char *) s;
        }

        s++;
    }

    return (*s == c) ? (char *) s : res;
}
