/*
 * =====================================================================================
 *
 *       Filename:  my_itoa.c
 *
 *    Description:  Convert number to string 
 *
 *        Version:  1.0
 *        Created:  08/06/2021 10:07:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <math.h>
#define MAXINTLEN   11

char *recursive_conv(unsigned int nmb, char *nptr);

char *my_itoa(int nmb)
{
    char *nptr = malloc(sizeof(char) * (MAXINTLEN + 1));
    char *nptr_start = nptr;

    if (nmb == 0)
    {
        *nptr++ = '0';
        *nptr = '\0';
        return --nptr;
    }

    if (nmb < 0)
    {
        nmb *= -1;
        *nptr++ = '-';
    }

    char *nptr_end = recursive_conv(nmb, nptr);
    *nptr_end = '\0';

    return nptr_start;
}

char *recursive_conv(unsigned int nmb, char *nptr)
{
    if (nmb != 0)
    {
        nptr = recursive_conv(nmb / 10, nptr);
        *nptr++ = '0' + (nmb % 10);
    }
    return nptr;
}
