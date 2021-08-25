/*
 * =====================================================================================
 *
 *       Filename:  ft_isascii.c
 *
 *    Description:  isascii lib implementation, which checks whether c is a 7-bit unsigned char value that fits into the ASCII character set. 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 08:10:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

int ft_isascii(int c)
{
    return (0 <= c && c <= 127);
}
