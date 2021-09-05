#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
  char *data = (char *) s;
  while(n-- != 0)
  {
    *data++ = '\0';
  }
}
