/*
 * =====================================================================================
 *
 *       Filename:  ft_strtrim.c
 *
 *    Description:  Allocates and returns a copy of the string given as argument without whitespaces at the begging or at the end of the string. 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 12:50:52 PM
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

    s--;

    while (s != s_start && (*s == ' ' || *s == '\t' || *s == '\n'))
    {
        s--;
    }

    s_end = (char *) s;
    size_t trim_len = (size_t)(s_end - s_start + 1);
    char *trim_s = NULL;

    if (s_start > s_end)
    {
        trim_s = (char *) malloc(sizeof(char));
        *trim_s = '\0';
        return trim_s;
    }

    trim_s = (char *) malloc(sizeof(char) * (trim_len + 1));
    s = s_start;

    while (s != s_end + 1)
    {
        *trim_s++ = *s++;
    }

    *trim_s = '\0';

    return trim_s - trim_len;
}
