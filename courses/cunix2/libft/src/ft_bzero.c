/*
 * =====================================================================================
 *
 *       Filename:  ft_bzero.c
 *
 *    Description:  Erases first n bytes from given pointer 
 *
 *        Version:  1.0
 *        Created:  08/09/2021 12:21:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
    char *s_byte = (char *) s;

    while (n-- != 0)
    {
        *s_byte++ = '\0';
    }
}
