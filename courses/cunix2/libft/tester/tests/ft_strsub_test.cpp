extern "C"
{
#define new hackademy
#include "libft.h"
#undef new
}

#include "sigsegv.hpp"
#include "check.hpp"
#include "leaks.hpp"
#include <string.h>

int iTest = 1;
int main(void)
{
	signal(SIGSEGV, sigsegv);
	title("ft_strsub\t: ")

	char * s = ft_strsub("hackademy", 0, 42000);
	/* 1 */ check(!strcmp(s, "hackademy"));
	/* 2 */ mcheck(s, strlen("hackademy") + 1); free(s); showLeaks();

	s = ft_strsub("hackademy", 1, 1);
	/* 3 */ check(!strcmp(s, "r"));
	/* 4 */ mcheck(s, 2); free(s); showLeaks();

	s = ft_strsub("hackademy", 100, 1);
	/* 5 */ check(!strcmp(s, ""));
	/* 6 */ mcheck(s, 1); free(s); showLeaks();

	char * str = strdup("1");
	s = ft_strsub(str, 42, 42000000);
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, 1); free(s); free(str); showLeaks();

	str = strdup("0123456789");
	s = ft_strsub(str, 9, 10);
	/* 9  mbueno-g */ check(!strcmp(s, "9"));
	/* 10  mbueno-g */ mcheck(s, 2); free(s); free(str); showLeaks();

	s = ft_strsub("42", 0, 0);
	/* 11  fcaquard */ check(!strcmp(s, ""));
	/* 12  fcaquard */ mcheck(s, 1); free(s); showLeaks();

	write(1, "\n", 1);
	return (0);
}