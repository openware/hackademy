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
#include <stdlib.h>

int iTest = 1;
int main(void)
{
  signal(SIGSEGV, sigsegv);
	title("ft_div\t: ")

  div_t res;

  res = ft_div(40, 5);
  /* 1 */ check(res.quot == 8 && res.rem == 0);
  res = ft_div(53, 8);
  /* 2 */ check(res.quot == 6 && res.rem == 5);
  res = ft_div(-40, 3);
  /* 3 */ check(res.quot == -13 && res.rem == -1);
  res = ft_div(-100, -6);
  /* 4 */ check(res.quot == 16 && res.rem == -4);

  write(1, "\n", 1);
	return (0);
}