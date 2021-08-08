/*
 * =====================================================================================
 *
 *       Filename:  my_atoi.c
 *
 *    Description:  Convert string to integer 
 *
 *        Version:  1.0
 *        Created:  08/06/2021 09:37:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

int my_atoi(const char *nptr)
{
    int sign = 1;
    int num = 0;

    if (*nptr == '-')
    {
        nptr++;
        sign = -1;
    }

    while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
    {
        num = 10 * num + (*nptr++ - '0');
    }

    return sign * num;
}
