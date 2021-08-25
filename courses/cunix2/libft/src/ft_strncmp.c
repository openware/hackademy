/*
 * =====================================================================================
 *
 *       Filename:  ft_strncmp.c
 *
 *    Description:  strncmp lib implementation, which compares the  first  (at
       most) n bytes of s1 and s2. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 05:18:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (*s1 != '\0'  && *s2 != '\0')
        {
            return 0;
        }

        if (*s1 != *s2)
        {
            return (int) *s1 - (int) *s2;
        }
        s1++;
        s2++;
    }

    return 0;
}
