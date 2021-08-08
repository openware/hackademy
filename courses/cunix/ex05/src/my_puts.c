/*
 * =====================================================================================
 *
 *       Filename:  my_puts.c
 *
 *    Description:  Prints string and return to next line 
 *
 *        Version:  1.0
 *        Created:  08/06/2021 12:23:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <unistd.h>

int my_puts(const char *s)
{
    while (*s != '\0')
    {
        write(1, s++, 1);
    }
    write(1, "\n", 1);

    return 1;
}
