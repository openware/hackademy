/*
 * =====================================================================================
 *
 *       Filename:  ft_div.c
 *
 *    Description:  div lib implementation, which computes the value numerator/denominator and returns the quotient and remainder in a structure named div_t that contains two integer members (in unspecified order) named quot and rem. The quotient is rounded toward zero. The result satisfies quot*denominator+rem = numerator.  
 *
 *        Version:  1.0
 *        Created:  08/25/2021 08:44:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdlib.h>

div_t ft_div(int numerator, int denominator)
{
    div_t res = {
        numerator / denominator,
        numerator % denominator
        };

    return res;
}
