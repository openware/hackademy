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
#include <stdlib.h>

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

int ft_abs(int x);
div_t ft_div(int numer, int denom);
char *ft_strstr(char *haystack, char *needle);
void *ft_memset(void *str, int c, size_t n);
void *ft_memcpy(void *dest, const char *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, unsigned long int count);
void *ft_memmove(void *dest, const char *src, unsigned long int n);
void *ft_memchr(void *str, int c, unsigned long int n);
int ft_memcmp ( const void * ptr1, const void * ptr2, unsigned long int num );



#endif
