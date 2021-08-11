/*
 * =====================================================================================
 *
 *       Filename:  ft_strsub.c
 *
 *    Description:  Returns substring from string of given length from given index 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 08:13:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

char *ft_strsub(const char *s, unsigned int start, size_t len)
{
    char *s_start = (char *) s;
    while (*s++ != '\0')
        ;
    unsigned int s_len = s - s_start - 1;

    if (s_len <= start)
    {
        start = s_len;
    }

    unsigned int new_s_len = s_len - start;
    if (new_s_len > len)
    {
        new_s_len = len;
    }
    char *new_s = (char *) malloc(sizeof(char) * (new_s_len + 1));

    s = s_start + start;
    while (s != s_start + start + new_s_len)
    {
        *new_s++ = *s++;
    }
    *new_s = '\0';

    return (new_s - new_s_len);
}
