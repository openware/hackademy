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
	title("ft_strrchr\t: ")
	char s[] = "hackademy";
	/* 1 */ check(ft_strrchr(s, 'h') == s); showLeaks();
	/* 2 */ check(ft_strrchr(s, 'm') == s + 7); showLeaks();
	/* 3 */ check(ft_strrchr(s, 'z') == 0); showLeaks();
	/* 4 */ check(ft_strrchr(s, 0) == s + strlen(s)); showLeaks();
	/* 5 */ check(ft_strrchr(s, 'h' + 256) == s); showLeaks();
	write(1, "\n", 1);
	return (0);
}
