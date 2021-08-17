/*
 * =====================================================================================
 *
 *       Filename:  strrchr.c
 *
 *        Created:  16.08.2021 21:51:08
 *       Compiler:  gcc
 *
 *         Author:  vinegod
 *
 * =====================================================================================
 */

char *ft_strrchr(char *str, char c)
{
    char *position = str;
    while (*str++)
        if (*str == c)
        {
            position = str;
        }
    return *position == c ? position : 0;
}