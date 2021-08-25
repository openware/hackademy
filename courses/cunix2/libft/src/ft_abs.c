/*
 * =====================================================================================
 *
 *       Filename:  ft_abs.c
 *
 *    Description:  abs lib implementation, which computes the absolute value of the integer argument j. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 08:36:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

int ft_abs(int j)
{
    return (j >= 0 ? j : -j);
}
