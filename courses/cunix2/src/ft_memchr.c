#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
  c %= 256;
  unsigned char *s_pos = (unsigned char *) s;
  while (n-- != 0)
  {
    if (*s_pos++ == c)
    {
      return (void *)(s_pos - 1);
    }
  }
  return 0;
}
