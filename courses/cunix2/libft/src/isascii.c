/*
 * =====================================================================================
 *
 *       Filename:  isascii.c
 *
 *        Created:  16.08.2021 22:34:31
 *       Compiler:  gcc
 *
 *         Author:  vinegod
 *
 * =====================================================================================
 */

int ft_isascii(int n)
{
    return n >= 0 && n <= 127;
}