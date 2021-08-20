/*
 * =====================================================================================
 *
 *       Filename:  my_strcpy.c
 *
 *    Description: own std strcpy implementation 
 *
 *        Version:  1.0
 *        Created:  08/20/2021 08:00:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  my_strcpy
 *  Description: std strcpy implementation.
 *  Note: the user must ensure that 'dest' buffer has enough space to have 'src' copied into it, otherwise undefined behavior!
 * =====================================================================================
 */

#include <stddef.h>

char *my_strcpy(char *dest, char *src)
{
    size_t i = 0;
    
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}
/* -----  end of function my_strcpy  ----- */
