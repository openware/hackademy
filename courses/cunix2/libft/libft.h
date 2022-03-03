#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>
#include <stdlib.h>

void ft_bzero(void *, size_t);
char *ft_strdup(const char *);
char *ft_strchr(const char *, int);
int ft_isalpha(int);
int ft_isdigit(int);
int ft_isascii(int);
int ft_toupper(int);
int ft_tolower(int);
int ft_abs(int);
div_t ft_div(int, int);
void *ft_memcpy(void *, const void *, size_t);
int ft_memcmp(const void *, const void *, int);
char *ft_strnstr(const char *, const char *, size_t);
int ft_strncmp(const char *, const char *, size_t);
char *ft_strjoin(char const *s1, char const *s2);
int ft_strlen(const char *);
char *ft_strtrim(char const *s);
char **ft_strsplit(char const *s, char c);
unsigned int ft_words(const char *, char);
size_t ft_strclen(const char *, char);
void ft_striter(char *s, void (*f)(char *));
void *ft_memset(void *, int, size_t);
char *ft_strstr(const char *, const char *);
#endif
