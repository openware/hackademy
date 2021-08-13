/*
 * =====================================================================================
 *
 *       Filename:  ft_strstr.c
 *
 *    Description:  Finds first occurence of string in given length
 *
 *        Version:  1.0
 *        Created:  08/10/2021 12:27:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    if (*needle == '\0')
    {
        return (char *) haystack;
    }

    char *haystack_r;
    char *needle_r;
    char *end_pos = (char *)(haystack + len);
    int found = 0;

    while (*haystack != '\0' && haystack != end_pos)
    {
        haystack_r = (char *) haystack;
        needle_r = (char *) needle;

        while (*needle_r != '\0')
        {
            if (haystack_r == end_pos || *haystack_r++ != *needle_r++)
            {
                found = 0;
                break;
            }
            else
            {
                found = 1;
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
