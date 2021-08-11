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
	title("ft_strstr\t: ")

      char	*s1 = "FF";
			char	*s2 = "see FF your FF return FF now FF";

			char	*i1 = strstr(s1, s2);
			char	*i2 = ft_strstr(s1, s2);

  /* 1 */ check(i1 == i2);

			s1 = "MZIRIBMZIRIBMZP";
			s2 = "MZIRIBMZP";

      i1 = strstr(s1, s2);
      i2 = ft_strstr(s1, s2);

  /* 2 */ check(i1 == i2);

      s2 = "FF";
			s1 = "see F your F return FF now FF";

			i1 = strstr(s1, s2);
			i2 = ft_strstr(s1, s2);

  /* 3 */ check(i1 == i2);

      s1 = "FF";
			s2 = "see F your F return F now FF";

			i1 = strstr(s1, s2);
			i2 = ft_strstr(s1, s2);

  /* 4 */ check(i1 == i2);

      s1 = "";
			s2 = "";

			i1 = strstr(s1, s2);
			i2 = ft_strstr(s1, s2);

  /* 5 */ check(i1 == i2);

			s1 = "can't found that";
			s2 = "in this !";

			i1 = strstr(s1, s2);
			i2 = ft_strstr(s1, s2);

  /* 6 */ check(i1 == i2);

      s1 = "";
			s2 = "oh no not the empty string !";

			i1 = strstr(s1, s2);
			i2 = ft_strstr(s1, s2);

  /* 7 */ check(i1 == i2);

      s1 = "AAAAAAAAAAAAA";

			i1 = strstr(s1, s1);
			i2 = ft_strstr(s1, s1);

  /* 8 */ check(i1 == i2);

  write(1, "\n", 1);
	return (0);
}