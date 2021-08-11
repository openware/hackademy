/*
 * =====================================================================================
 *
 *       Filename:  ft_striteri.c
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

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    char *s_start = s;

    while (*s != '\0')
    {
        (*f)(s - s_start, s);
        s++;
    }
}
