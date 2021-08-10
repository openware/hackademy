/*
 * =====================================================================================
 *
 *       Filename:  ft_isascii.c
 *
 *    Description:  Checks for a 7-bit unsigned char (0-127) 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 11:48:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

int ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}
