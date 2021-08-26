/*
 * =====================================================================================
 *
 *       Filename:  ft_strstr.c
 *
 *    Description:  strstr lib implementation, which inds the first occurrence of the substring needle in the string haystack. The terminating null bytes ('\0') are not compared.  
 *
 *        Version:  1.0
 *        Created:  08/26/2021 12:55:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

char *ft_strstr(const char *haystack, const char *needle)
{
    if (*haystack == '\0')
    {
        return (char *) needle;
    }

    if (*needle == '\0')
    {
        return (char *) haystack;
    }

    char *h_pos;
    char *n_pos;
    int found = 0;

    while (*haystack != '\0')
    {
        h_pos = (char *) haystack;
        n_pos = (char *) needle;

        while (*n_pos != '\0')
        {
            if (*h_pos++ == *n_pos++)
            {
                found = 1;
            }
            else
            {
                found = 0;
                break;
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
