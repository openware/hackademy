/*
 * =====================================================================================
 *
 *       Filename:  ft_strncmp.c
 *
 *    Description:  Compares first n symbols of strings 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 09:58:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stddef.h>

int ft_strncmp(const char *string1, const char *string2, size_t num)
{
    num++;

    while (*string1 != '\0' && *string2 != '\0' && --num != 0)
    {
        if (*string1 > *string2)
        {
            return 1;
        }
        else if (*string1 < *string2)
        {
            return -1;
        }
        string1++;
        string2++;
    }

    if (*string1 == *string2 || num == 0)
    {
        return 0;
    }
    else if (*string1 == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
