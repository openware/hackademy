/*
 * =====================================================================================
 *
 *       Filename:  bzero.c
 *
 *        Created:  16.08.2021 13:48:25
 *       Compiler:  gcc
 *
 *         Author:  vinegod
 *
 * =====================================================================================
 */

void ft_bzero(void *start, long unsigned len)
{
    char *s = start;
    for (long unsigned int i = 0; i < len; i++)
    {
        s[i] = '\0';
    }
}
