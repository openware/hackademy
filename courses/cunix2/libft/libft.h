#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>
#include <stdlib.h>

void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_abs(int j);
div_t ft_div(int num, int denom);
void *ft_memcpy(void *__restrict__ dest, const void *__restrict__ src, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
size_t ft_strlen(const char *s);
char *ft_strtrim(char const *s);
char **ft_strsplit(char const *s, char c);
unsigned int ft_words(const char *s, char c);
size_t ft_strclen(const char *s, char c);
void ft_striter(char *s, void (*f)(char *));
void *ft_memset(void *s, int c, size_t n);
char *ft_strstr(const char *haystack, const char *needle);
#endif
