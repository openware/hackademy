/*
 * =====================================================================================
 *
 *       Filename:  ft_striter.c
 *
 *    Description:  Applies function to each character 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 04:59:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

void ft_striter(char *s, void (*f)(char *))
{
    while (*s != '\0')
    {
        (*f)(s);
        s++;
    }
}
