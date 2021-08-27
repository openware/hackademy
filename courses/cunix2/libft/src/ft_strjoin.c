/*
 * =====================================================================================
 *
 *       Filename:  ft_strjoin.c
 *
 *    Description:  Allocates and returns a new "fresh" string ending with '\0', result of concatenation of s1 and s2. 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 12:36:46 PM
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

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t l1 = ft_strlen(s1);
    size_t l2 = ft_strlen(s2);
    size_t concat_l = l1 + l2;

    char *concat = (char *) malloc(sizeof(char) * (concat_l + 1));

    if (!concat)
    {
        return 0;
    }

    while (l1-- != 0)
    {
        *concat++ = *s1++;
    }

    while (l2-- != 0)
    {
        *concat++ = *s2++;
    }

    *concat = '\0';

    return concat - concat_l;
}
