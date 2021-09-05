#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void ft_bzero(void *s, size_t n);
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *__restrict__ dest, const void *__restrict__ src, size_t n);
void *ft_memccpy(void *__restrict__ dest, const void *__restrict__ src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strnstr(const char *haystack, const char *needle, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_abs(int j);
int ft_memcmp(const void *s1, const void *s2, size_t n);
div_t ft_div(int num, int denom);

#endif
