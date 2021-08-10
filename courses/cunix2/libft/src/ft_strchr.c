/*
 * =====================================================================================
 *
 *       Filename:  ft_strchr.c
 *
 *    Description:  Finds first occurence of given character 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 10:48:11 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

char *ft_strchr(const char *s, int c)
{
    c %= 256;

    while (*s != '\0')
    {
        if (*s == c)
        {
            return (char *) s;
        }
        s++;
    }

    return (*s == c) ? (char *) s : 0;
}
