#include <stddef.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
  unsigned char *dest_pos = (unsigned char *) dest;
  unsigned char *src_pos = (unsigned char *) src;
  unsigned char *temp_arr = (unsigned char *) malloc(sizeof(unsigned char) * n);
  size_t i = n;
  while (i-- != 0)
  {
    *temp_arr++ = *src_pos++;
  }
  i = n;
  temp_arr -= i;
  while (i-- != 0)
  {
    *dest_pos++ = *temp_arr++;
  }

  free(temp_arr - n);
  return dest;
}
