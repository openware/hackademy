/*
 * =====================================================================================
 *
 *       Filename:  ft_strnstr.c
 *
 *    Description:  strnstr implementation, which locates the first occurrence of the null-terminated string needle in the string haystack, where not more than n characters are searched. Characters that appear after a `\0' character are not searched. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 01:27:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    if (*needle == '\0')
    {
        return (char *) haystack;
    }

    char *h_pos;
    char *n_pos;
    char *end_pos = (char *)(haystack + n);
    int found = 0;

    while (*haystack != '\0' && haystack != end_pos)
    {
        h_pos = (char *) haystack;
        n_pos = (char *) needle;

        while (*n_pos != '\0')
        {
            if (h_pos != end_pos && *h_pos++ == *n_pos++)
            {
                found = 1;
            }
            else
            {
                found = 0;
                break;
            }

        }

        if (found)
        {
            return (char *) haystack;
        }

        haystack++;
    }

    return 0;
}
