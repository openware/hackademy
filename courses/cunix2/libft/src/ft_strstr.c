/*
 * =====================================================================================
 *
 *       Filename:  ft_strstr.c
 *
 *    Description:  Findst first occurence of given string 
 *
 *        Version:  1.0
 *        Created:  08/10/2021 12:27:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enthony Phil (ep), jellyskate1999@gmail.com
 *        Company:  Openware, Inc.
 *
 * =====================================================================================
 */

char *ft_strstr(const char *haystack, const char *needle)
{
    char *haystack_r;
    char *needle_r;
    int found = 0;

    while (*haystack != '\0')
    {
        haystack_r = (char *) haystack;
        needle_r = (char *) needle;

        while (*needle_r != '\0')
        {
            if (*haystack_r++ != *needle_r++)
            {
                found = 0;
                break;
            }
            else
            {
                found = 1;
            }
        }

        if (found)
        {
            return (char *) haystack;
        }

        haystack++;
    }

    return 0;
}
