/*
 * =====================================================================================
 *
 *       Filename:  ft_tolower.c
 *
 *    Description:  Makes character to be lowercase 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 11:55:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c += 32;
    }

    return c;
}
