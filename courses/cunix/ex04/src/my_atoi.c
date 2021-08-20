/*
 * =====================================================================================
 *
 *       Filename:  my_atoi.c
 *
 *    Description:  own implementation of std atoi function 
 *
 *        Version:  1.0
 *        Created:  08/20/2021 09:37:38 PM
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
 *         Name:  my_atoi
 *  Description:  converts array of chars 'nptr' to a number up to a non-digit character. Any leading spaces are skipped, the sign char is read if present. If a string can't be parsed to a number, 0 is returned. 
 * =====================================================================================
 */
int my_atoi(const char *nptr)
{
    int num = 0, sign = 1, i = 0;

    // skip leading spaces
    while (nptr[i] == ' ')
    {
        i++;
    }

    // read the sign of a number if any
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    // read digits one by one
    while ('0' <= nptr[i] && nptr[i] <= '9')
    {
        num = num * 10 + (nptr[i] - '0');
        i++;
    }

    num *= sign;

    return num;
}
/* -----  end of function my_atoi  ----- */
