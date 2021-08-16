#include <stdio.h>
void ft_bzero(void *s, size_t n);
int ft_isascii(int c);
int ft_isdigit(int c);
char *ft_strchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr( const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
void *ft_memccpy(void *dest, const void *src, int c, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strmap(char const *s, char (*f)(char));
char * ft_strsub(char const *s, unsigned int start, size_t len);
char *  ft_strtrim(char const *s);
