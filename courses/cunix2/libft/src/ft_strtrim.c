/*
 * =====================================================================================
 *
 *       Filename:  ft_strtrim.c
 *
 *    Description:  Removes whitespaces at the beginning or at the end of the
 *                  string and returns pointer to new
 *
 *        Version:  1.0
 *        Created:  08/11/2021 09:59:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

char *ft_strtrim(const char *s)
{
    char *s_start = NULL;
    char *s_end = NULL;
    while (*s != '\0' && (*s == ' ' || *s == '\t' || *s == '\n'))
    {
        s++;
    }
    s_start = (char *) s;

    while (*s != '\0')
    {
        s++;
    }
    while (--s != s_start && (*s == ' ' || *s == '\t' || *s == '\n'))
        ;
    s_end = (char *) s;

    char *new_s = NULL;
    if (s_start > s_end)
    {
        new_s = malloc(1);
        *new_s = '\0';
        return new_s;
    }
    new_s = malloc(sizeof(char) * (s_end - s_start + 2));
    s = s_start;
    while (s != s_end + 1)
    {
        *new_s++ = *s++;
    }
    *new_s = '\0';

    return (new_s - (s_end - s_start + 1));
}

/*
int main(void)
{
    char *s = ft_strtrim("   tripouille");
    s = ft_strtrim("tripouille   ");
    s = ft_strtrim("   tripouille   ");
    s = ft_strtrim("     ");
    s = ft_strtrim("");
    s--; s++;
}
*/
