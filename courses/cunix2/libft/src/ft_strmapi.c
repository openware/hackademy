/*
 * =====================================================================================
 *
 *       Filename:  ft_strmapi.c
 *
 *    Description:  Applies given function to each character and writes results to
 *                  new string
 *
 *        Version:  1.0
 *        Created:  08/10/2021 07:38:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

unsigned int my_strlen(const char *);

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    const char *s_start = s;
    unsigned int s_len = my_strlen(s);
    char *new_s = (char *) malloc(sizeof(char) * (s_len + 1));

    for (; *s != '\0'; s++, new_s++)
    {
        *new_s = (*f)(s - s_start, *s);
    }
    *new_s = *s;

    return (new_s - s_len);
}

unsigned int my_strlen(const char *s)
{
    const char *s_start = s;
    while (*s++ != '\0')
        ;
    return (s - s_start - 1);
}
