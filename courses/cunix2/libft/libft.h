#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>

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

#endif
