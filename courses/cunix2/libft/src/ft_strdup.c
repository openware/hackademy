/*
 * =====================================================================================
 *
 *       Filename:  ft_strdup.c
 *
 *    Description:  strdup lib implementation, which returns a pointer to a new string which is a duplicate of the string s. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 04:41:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdlib.h>

char *ft_strdup(const char *s)
{
    char *str = (char *) s;
    int len = 1;
    while (*str++ != '\0')
    {
        len++;
    }

    str = str - len;

    char *new_str = (char *) malloc(sizeof(char *) * (size_t) len);
    
    while (*str != '\0')
    {
        *new_str++ = *str++;
    }

    *new_str = '\0';

    return new_str - len + 1;
}
