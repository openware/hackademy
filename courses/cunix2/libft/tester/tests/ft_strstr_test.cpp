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

      char	*s1 = (char *) "FF";
			char	*s2 = (char *) "see FF your FF return FF now FF";

			char	*i1 = strstr(s2, s1);
			char	*i2 = ft_strstr(s2, s1);

  /* 1 */ check(i1 == i2);

			s1 = (char *) "MZIRIBMZIRIBMZP";
			s2 = (char *) "MZIRIBMZP";

      i1 = strstr(s2, s1);
      i2 = ft_strstr(s2, s1);

  /* 2 */ check(i1 == i2);

      s2 = (char *) "FF";
			s1 = (char *) "see F your F return FF now FF";

			i1 = strstr(s2, s1);
			i2 = ft_strstr(s2, s1);

  /* 3 */ check(i1 == i2);

      s1 = (char *) "FF";
			s2 = (char *) "see F your F return F now FF";

			i1 = strstr(s2, s1);
			i2 = ft_strstr(s2, s1);

  /* 4 */ check(i1 == i2);

      s1 = (char *) "";
			s2 = (char *) "";

			i1 = strstr(s2, s1);
			i2 = ft_strstr(s2, s1);

  /* 5 */ check(i1 == i2);

			s1 = (char *) "can't found that";
			s2 = (char *) "in this !";

			i1 = strstr(s2, s1);
			i2 = ft_strstr(s2, s1);

  /* 6 */ check(i1 == i2);

      s1 = (char *) "";
			s2 = (char *) "oh no not the empty string !";

			i1 = strstr(s2, s1);
			i2 = ft_strstr(s2, s1);

  /* 7 */ check(i1 == i2);

      s1 = (char *) "AAAAAAAAAAAAA";

			i1 = strstr(s1, s1);
			i2 = ft_strstr(s1, s1);

  /* 8 */ check(i1 == i2);

  write(1, "\n", 1);
	return (0);
}
