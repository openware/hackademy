/*
 * =====================================================================================
 *
 *       Filename:  my_itoa.c
 *
 *    Description:  own implementation of itoa function 
 *
 *        Version:  1.0
 *        Created:  08/20/2021 10:46:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  my_itoa
 *  Description:  converts 'nmb' to array of char 
 * =====================================================================================
 */
char *my_itoa(int nmb)
{
    // using malloc to allocate memory from the heap
    char *str = malloc(sizeof nmb * CHAR_BIT + 1 + 1);
    sprintf(str, "%d", nmb);
    return str;
}
/* -----  end of function my_itoa  ----- */
