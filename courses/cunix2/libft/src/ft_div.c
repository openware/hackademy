/*
 * =====================================================================================
 *
 *       Filename:  ft_div.c
 *
 *    Description:  Compute quotient and remainder of an integer division 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 12:12:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

div_t ft_div(int numerator, int denominator)
{
    div_t result = {.quot = numerator / denominator, .rem = numerator % denominator};
    return result;
}
