#include <stdlib.h>

char *ft_strdup(const char *s)
{
  char *str = (char *) s;
  int len = 1;
  while (*str++ != '\0')
  {
    len++;
  }
  str = str - len;
  char *new_str = (char *) malloc((size_t) len);
  while (*str != '\0')
  {
    *new_str++ = *str++;
  }
  *new_str = '\0';
  return new_str - len + 1;
}
