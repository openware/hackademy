/*
 * =====================================================================================
 *
 *       Filename:  ft_toupper.c
 *
 *    Description:  Makes character to be uppercase 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 11:52:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        c -= 32;
    }

    return c;
}
