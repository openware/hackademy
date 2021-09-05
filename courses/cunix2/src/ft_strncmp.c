#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    if (*s1 != '\0'  && *s2 != '\0')
    {
      return 0;
    }
    if (*s1 != *s2)
    {
      return (int) *s1 - (int) *s2;
    }
    s1++;
    s2++;
  }
  return 0;
}
