/*
 * =====================================================================================
 *
 *       Filename:  ft_toupper.c
 *
 *    Description:  toupper lib implementation, which if  c  is a lowercase letter, toupper() returns its uppercase equivalent, if an uppercase representation exists in the current locale. Otherwise, it  returns c. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 08:16:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

int ft_toupper(int c)
{
    if ('a' <= c && c <= 'z')
    {
        c -= 32;
    }

    return c;
}
