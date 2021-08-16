/*
 * =====================================================================================
 *
 *       Filename:  libft.h
 *
 *        Created:  16.08.2021 14:01:48
 *       Compiler:  gcc
 *
 *         Author:  vinegod
 *
 * =====================================================================================
 */

#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>

void ft_bzero(void *s, size_t n);
char *ft_strdup(char *str);
int ft_strncmp(char *str1, char *str2, size_t num);
char *ft_strchr(const char *str, char c);
char *ft_strrchr(char *str, char c);
int ft_isalpha(int n);
int ft_isdigit(int n);
int ft_isascii(int n);
int ft_toupper(int n);
int ft_tolower(int n);
#endif
