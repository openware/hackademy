#include <stddef.h>

void *ft_memccpy(void *restrict dest, const void *restrict src, int c, size_t n)
{
  unsigned char *dest_pos = (unsigned char *) dest;
  unsigned char *src_pos = (unsigned char *) src;
  c %= 256;
  while (n-- != 0)
  {
    *dest_pos++ = *src_pos;
    if (*src_pos == c)
    {
      return (void *) dest_pos;
    }
    src_pos++;
  }
  return 0;
}
