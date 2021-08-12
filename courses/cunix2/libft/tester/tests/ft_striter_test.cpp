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

void f_striter(char *s)
{
  *s = 'F';
}

int iTest = 1;
int main(void)
{
  signal(SIGSEGV, sigsegv);
	title("ft_striter\t: ")

  char	b[] = "override this !";
  char	b2[0xF0];
  size_t	size = strlen(b);

  for (size_t i = 0; i < size; i++)
    f_striter(b2 + i);
  b2[size] = 0;
  ft_striter(b, f_striter);
  check(!strcmp(b, b2));

  write(1, "\n", 1);
	return (0);
}