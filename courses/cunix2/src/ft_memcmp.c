#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
  unsigned char *s1_pos = (unsigned char *) s1;
  unsigned char *s2_pos = (unsigned char *) s2;
  int diff;
  while (n-- != 0)
  {
    diff = *s1_pos++ - *s2_pos++;
    if (diff != 0)
    {
      return diff;
    }
  }
  return 0;
}
