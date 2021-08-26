/*
 * =====================================================================================
 *
 *       Filename:  ft_striter.c
 *
 *    Description:  Applies the function f to each character of the string passed as an argument. Each character is passed by address to f to be modified if necessary. 
 *
 *        Version:  1.0
 *        Created:  08/26/2021 05:59:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

void ft_striter(char *s, void (*f)(char *))
{
    while (*s != '\0')
    {
        f(s);
        s++;
    }
}
