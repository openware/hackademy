/*
 * =====================================================================================
 *
 *       Filename:  ft_strdup.c
 *
 *    Description:  Copy string from constant to pointer 
 *
 *        Version:  1.0
 *        Created:  08/09/2021 01:21:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

char *ft_strdup(char *s)
{
    int len = 1;
    while (*s++ != '\0')
    {
        ++len;
    }
    s = s - len;

    char *new_s = (char *) malloc(sizeof(char *) * (size_t) len);
    while (*s != '\0')
        *new_s++ = *s++;
    *new_s = *s;

    return new_s - len + 1;
}
