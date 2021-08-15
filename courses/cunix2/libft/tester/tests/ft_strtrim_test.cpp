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
	title("ft_strtrim\t: ")

	char * s = ft_strtrim("   hackademy");
	/* 1 */ check(!strcmp(s, "hackademy"));
	/* 2 */ mcheck(s, strlen("hackademy") + 1); free(s); showLeaks();

	s = ft_strtrim("hackademy   ");
	/* 3 */ check(!strcmp(s, "hackademy"));
	/* 4 */ mcheck(s, strlen("hackademy") + 1); free(s); showLeaks();

	s = ft_strtrim("   hackademy   ");
	/* 5 */ check(!strcmp(s, "hackademy"));
	/* 6 */ mcheck(s, strlen("hackademy") + 1); free(s); showLeaks();
	
	s = ft_strtrim("      ");
	/* 7 */ check(!strcmp(s, ""));
	/* 8 */ mcheck(s, 1); free(s); showLeaks();

	s = ft_strtrim("");
	/* 9 */ check(!strcmp(s, ""));
	/* 10 */ mcheck(s, 1); free(s); showLeaks();

	s = ft_strtrim("123");
	/* 11 */ check(!strcmp(s, "123"));
	/* 12 */ mcheck(s, 4); free(s); showLeaks();

	s = ft_strtrim(" 12  34   ");
	/* 13 */ check(!strcmp(s, "12  34"));
	/* 14 */ mcheck(s, 1); free(s); showLeaks();
	write(1, "\n", 1);
	return (0);
}