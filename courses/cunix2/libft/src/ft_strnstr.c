//#include "libft.h"
#include <stdio.h>//FOR NULL
/*int ft_memcmp(char *s1, char *s2, int n)
{
    while (n--)
        if (*s1++ != * s2++)
        {
            return *(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1);
        }
    return 0;
}*/

int f_strncmp( const char * s1, const char * s2, int n )
{
    while ( n && *s1 && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }
    if ( n == 0 )
    {
        return 0;
    }
    else
    {
        return ( *(unsigned char *)s1 - *(unsigned char *)s2 );
    }
}
/*char *ft_strnstr( char *haystack, char *needle,int len)
{
        int i;
        

        if (0 == len)
                return (char *)haystack;

        for (i=0; i<=(int)(len); i++)
        {
                if ((haystack[0] == needle[0]) &&
                        (0 == ft_memcmp(haystack, needle, len)))
                        return (char *)haystack;

                haystack++;
        }
        return 0;
}*/
int ft_strlen(const char *s) {
    const char *p = s;
    while (*s) ++s;
    return s - p;
}
char *ft_strnstr(const char *haystack, const char *needle, int len)
{
	char c, sc;
	int len2=0;
    //int a=0;

	if ((c = *needle++) != '\0') {
		len2 = ft_strlen(needle);
		do {
			do {
				if (len-- < 1 || (sc = *haystack++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len2 > len)
				return (NULL);
            //a=strncmp(haystack, needle, len2);
		} while (f_strncmp(haystack, needle, len2) != 0);
		haystack--;
	}
	return ((char *)haystack);
}

/*
char *strnstr(char *haystack, char *needle, int len) {
    if (len == 0) return haystack; 
    while (haystack = ft_strchr(haystack, needle[0])) {
        if (!ft_strncmp(haystack, needle, len)) return haystack;
        haystack++; }
    return 0;
}*/