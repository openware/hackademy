/*
 * =====================================================================================
 *
 *       Filename:  ft_strmap.c
 *
 *    Description:  Applies the function f to each character of the string given as an argument to create a "fresh" new string resulting from the successive applications of f. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 07:09:40 PM
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

char *ft_strmap(char const *s, char (*f)(char))
{
    size_t len = ft_strlen(s);
    char *new_s = (char *) malloc(sizeof(char) * (len + 1));

    for (; *s != '\0'; s++, new_s++)
    {
        *new_s = f(*s);
    }

    *new_s = '\0';

    return (new_s - len);
}
