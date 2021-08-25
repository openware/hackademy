/*
 * =====================================================================================
 *
 *       Filename:  ft_isdigit.c
 *
 *    Description:  isdigit lib implementation, which checks for a digit (0 through 9). 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 08:09:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

int ft_isdigit(int c)
{
    return ('0' <= c && c <= '9');
}
