/*
 * =====================================================================================
 *
 *       Filename:  ft_strrchr.c
 *
 *    Description:  Finds last occurence of given character 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 11:00:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

char *ft_strrchr(const char *s, int c)
{
    if (*s == '\0')
    {
        return (*s == c) ? (char *) s : 0;
    }

    char *pos = ft_strrchr(s + 1, c);
    if (pos == 0 && *s == c % 256)
    {
        return (char *) s;
    }

    return pos;
}
