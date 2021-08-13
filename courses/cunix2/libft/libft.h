#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>
#include <stdlib.h>

void ft_bzero(void *s, size_t n);
char *ft_strdup(char *s);
int ft_strncmp(const char *string1, const char *string2, size_t num);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_toupper(int c);
int ft_tolower(int c);

int ft_abs(int j);
div_t ft_div(int numerator, int denominator);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);

void ft_striter(char *s, void (*f)(char *));
char *ft_strmap(char const *s, char (*f)(char));
char *ft_strsub(const char *s, unsigned int start, size_t len);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strtrim(const char *s);
char **ft_strsplit(const char *s, char c);

#endif
