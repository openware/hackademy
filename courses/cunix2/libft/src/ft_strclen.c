/*
 * =====================================================================================
 *
 *       Filename:  ft_strclen.c
 *
 *    Description:  Calculates and returns the lenght of the word s before the c character. 
 *
 *        Version:  1.0
 *        Created:  08/27/2021 02:35:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include "../libft.h"

size_t ft_strclen(const char *s, char c)
{
    char *word_end = ft_strchr(s, c);

    if (!word_end)
    {
        return ft_strlen(s);
    }

    return word_end - s;
}
