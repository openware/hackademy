/*
 * =====================================================================================
 *
 *       Filename:  strncmp.c
 *
 *        Created:  16.08.2021 20:13:52
 *       Compiler:  gcc
 *
 *         Author:  vinegod 
 *
 * =====================================================================================
 */

#define size_t unsigned long long



int ft_strncmp(char* str1, char* str2, size_t num) {
    for (; *str1 == *str2 && num-- > 0; str1++, str2++)
        ;
    return num == 0 ? 0 : *str1 - *str2;
}
