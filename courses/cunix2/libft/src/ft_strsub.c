/*
 * =====================================================================================
 *
 *       Filename:  ft_strsub.c
 *
 *    Description:  Allocates and returns a "fresh" substring from the string given as an argument. The substring begins at index start and is of size len. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 07:30:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "../libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *s_start = (char *) s;
    size_t s_len = ft_strlen(s);

    if (start >= s_len)
    {
        start = s_len;
    }

    size_t subs_len = s_len - start;

    if (subs_len > len)
    {
        subs_len = len;
    }

    char *substr = (char *) malloc(sizeof(char) * (subs_len + 1));

    if (!substr)
    {
        return 0;
    }

    s += start;

    while (s != s_start + start + subs_len)
    {
        *substr++ = *s++;
    }

    *substr = '\0';

    return substr - subs_len;
}
