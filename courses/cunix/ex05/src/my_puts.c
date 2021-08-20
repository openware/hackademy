/*
 * =====================================================================================
 *
 *       Filename:  my_puts.c
 *
 *    Description:  own implementation of std puts function using only write 
 *
 *        Version:  1.0
 *        Created:  08/20/2021 11:26:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  my_puts
 *  Description:  writes the string s and a trailing newline to stdout. 
 * =====================================================================================
 */
int my_puts(const char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if (putchar(s[i]) == EOF)
        {
            return EOF;
        }
        i++;
    }

    if (putchar('\n') == EOF)
    {
        return EOF;
    }

    return 1;
}
/* -----  end of function my_puts  ----- */
