
//#include "libft.h" 


void ft_bzero(void *s, int n)
{
    char *c = s; 
    int i;
    for (i = 0; i < n; ++i)
    {
        c[i] = '\0';
    }
}