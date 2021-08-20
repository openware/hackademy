/*
 * =====================================================================================
 *
 *       Filename:  my_strlen.c
 *
 *    Description: own implementation of std strel function 
 *
 *        Version:  1.0
 *        Created:  08/20/2021 12:48:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

unsigned int my_strlen(char *str)
{
    unsigned int len = 0;
    while (*(str++) != '\0')
    {
        len++;
    }
    return len;
}
/* -----  end of function my_strlen  ----- */
