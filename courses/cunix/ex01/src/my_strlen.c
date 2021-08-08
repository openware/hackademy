/*
 * =====================================================================================
 *
 *       Filename:  my_strlen.c
 *
 *    Description:  Find length of string 
 *
 *        Version:  1.0
 *        Created:  08/05/2021 03:05:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

unsigned int my_strlen(char *str)
{
    unsigned int length = 0;

    while (*str++ != '\0')
    {
        ++length;
    }

    return length;
}
