/*
 * =====================================================================================
 *
 *       Filename:  my_strcpy.c
 *
 *    Description:  Copy one string to another 
 *
 *        Version:  1.0
 *        Created:  08/05/2021 04:14:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    char *res = dest;

    while (dest != 0 && *src != '\0')
    {
        *dest++ = *src++;
    }

    if (*src == '\0')
    {
        *dest = *src;
    }

    return res;
}
