/*
 * =====================================================================================
 *
 *       Filename:  ft_tolower.c
 *
 *    Description:  tolower lib implementation, which if c is an uppercase letter, tolower() returns its lowercase  equivalent, if  a  lowercase representation exists in the current locale. Otherwise, it returns c. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 08:20:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

int ft_tolower(int c)
{
    if ('A' <= c && c <= 'Z')
    {
        c += 32;
    }

    return c;
}
