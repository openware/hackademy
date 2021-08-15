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
	title("ft_abs\t: ")

  /* 1 */ check(ft_abs(-1) == 1);
  /* 2 */ check(ft_abs(0) == 0);
  /* 3 */ check(ft_abs(21) == 21);
  /* 4 */ check(ft_abs(-2147483647) == 2147483647);

  write(1, "\n", 1);
	return (0);
}