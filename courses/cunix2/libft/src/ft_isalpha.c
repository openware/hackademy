/*
 * =====================================================================================
 *
 *       Filename:  ft_isalpha.c
 *
 *    Description:  Checks for an alphabetic character 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 11:40:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
