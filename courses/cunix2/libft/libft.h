#ifndef LIBFT_H
# define LIBFT_H


typedef struct {
    int quot;      /* quotient  */
    int rem;       /* remainder */
} div_t;

void ft_bzero(void *s, int n);
char ft_strdup(char* src);
int ft_memcmp(char* s1, char* s2,int n );
char* ft_strchr(char* s, int c);
char *ft_strrchr(char *s, int c);
int ft_isalpha(int c);
int ft_isdigit (int c);
int ft_isascii (int c );
int ft_toupper (int c );
int ft_tolower( int c );
int ft_abs( int j );

div_t ft_div(int numer, int denom);

char* ft_strstr(char* str, char* substr);
//int compare1(const char *X, const char *Y);

#endif 