/*
 * =====================================================================================
 *
 *       Filename:  ft_strjoin.c
 *
 *    Description:  Concatenates 2 given strings and returns pointer to new 
 *
 *        Version:  1.0
 *        Created:  08/11/2021 09:48:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    int s_len = 0;
    char *s1_start = (char *) s1;
    char *s2_start = (char *) s2;

    while (*s1++ != '\0')
    {
        s_len++;
    }
    while (*s2++ != '\0')
    {
        s_len++;
    }

    char *s = malloc(sizeof(char) * (s_len + 1));
    s1 = s1_start;
    s2 = s2_start;
    while (*s1 != '\0')
    {
        *s++ = *s1++;
    }
    while (*s2 != '\0')
    {
        *s++ = *s2++;
    }
    *s = '\0';

    return (s - s_len);
}
