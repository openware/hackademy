/*
 * =====================================================================================
 *
 *       Filename:  my_strcmp.c
 *
 *    Description:  Compare given strings 
 *
 *        Version:  1.0
 *        Created:  08/05/2021 03:26:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */
#include <stdlib.h>

int abs(int);

int my_strcmp(char *s1, char *s2)
{
    int diff;

    while ((diff = *s1++ - *s2++) == 0 && *s1 != '\0')
        ;

    return (!diff ? diff : (diff / abs(diff)));
}
