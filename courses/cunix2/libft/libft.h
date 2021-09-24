#ifndef LIBFT_H
# define LIBFT_H
#define NULL __DARWIN_NULL

#include <stdlib.h>


void ft_bzero(void *s, int n);
char ft_strdup(char* src);//none ctest

//int ft_memcmp(char* s1, char* s2,int n ); 
//DAY FIRST ( THE SAME FUNCTION AS IT WAS IN THE SECOND DAY)
//IT WORKS

char* ft_strchr(char* s, int c);
char *ft_strrchr(char *s, int c);//none ctest
int ft_isalpha(int c);
int ft_isdigit (int c);
int ft_isascii (int c );
int ft_toupper (int c );
int ft_tolower( int c );
//DAY 2////////////////////////////////////////////////////////////
int ft_abs( int j );


div_t ft_div(int numer, int denom);

char *ft_strnstr( char *haystack,  char *needle,int len);//2.KO 3.KO 4.KO 
char* ft_strstr(char* str, char* substr);
void* ft_memset(void* dst,int c,unsigned int len);
void* ft_memcpy(void *dst, const void *src, int length);
void* ft_memccpy(void *dest, const void *src, int c, int n);//none ctest
void* ft_memmove(void *dst, const void *src, int length);//none ctest
void* ft_memchr(void *buf, int ch, int length);//none stest
int ft_memcmp(void* s1, void* s2, int length);

//DAY 3///////////////////////////////////////////////////////////////
void ft_striter(char *s, void(*f)(char *));
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s);
char **ft_strsplit(char *s, char c);

#endif 