#include <stdlib.h>
void ft_bzero(void * s, unsigned int n);
char *ft_strdup(const char *src);
int ft_strncmp(const char *string1, const char *string2, unsigned int num);
char *ft_strchr(const char *string, int symbol);
char *ft_strrchr(const char *str, int ch);
int ft_isalpha(int ch);
int ft_isdigit(int ch);
int ft_isascii(int ch);
int ft_toupper(int ch);
int ft_tolower(int ch);

int ft_abs(int num);

/*typedef struct divid {
	int quot;
	int rem;
}	div_t;*/
div_t ft_div(int num, int denom);
char *ft_strstr(const char *str1, const char *str2);
char *ft_strnstr(const char *str1, const char *str2, unsigned int n);
void *ft_memset(void *destination, int ch, unsigned int n);
void *ft_memcpy(void *dest, const void *src, unsigned int num);
void *ft_memccpy(void *dest, const void *src, int ch, unsigned int num);
void *ft_memmove(void *dest, const void *src, unsigned int n);
void *ft_memchr(const void *arr, int c, unsigned int n);
int ft_memcmp(const void *buf1, const void *buf2, unsigned int count);


void ft_striter(char *s, void (*f)(char *));
char *ft_strmap(char const *s, char (*f)(char));
char *ft_strsub(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s);
char **ft_strsplit(char const *s, char c);
