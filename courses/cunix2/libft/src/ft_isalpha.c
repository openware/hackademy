/*
 * =====================================================================================
 *
 *       Filename:  ft_isalpha.c
 *
 *    Description:  isalpha lib implementation, which checks its argument for an alphabetic character. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 07:58:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

int ft_isalpha(int c)
{
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
