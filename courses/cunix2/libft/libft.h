/*
 * =====================================================================================
 *
 *       Filename:  libft.h
 *
 *    Description:  Prototypes of implemented lib functions 
 *
 *        Version:  1.0
 *        Created:  08/25/2021 01:52:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>

void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_toupper(int c);
int ft_tolower(int c);

#endif
