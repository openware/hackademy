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


char f_strmap(char c)
{
  return (c + 7);
}

int iTest = 1;
int main(void)
{
  signal(SIGSEGV, sigsegv);
	title("ft_strmap\t: ")

  char	b[16] = "override this !";
  char	b2[0xF0];
  size_t	size = strlen(b);

  for (size_t i = 0; i < size; i++)
    b2[i] = f_strmap(b[i]);

  b2[size] = 0;
  char	*ret = ft_strmap(b, f_strmap);
  check(!strcmp(b2, ret));

  write(1, "\n", 1);
	return (0);
}