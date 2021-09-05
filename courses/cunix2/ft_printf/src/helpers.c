#include <stdlib.h>
#include <limits.h>

char *_numtostr(unsigned int num, char *str)
{
  if (num != 0)
  {
    str = (char *) _numtostr(num / 10, str);
    *str++ = '0' + (num % 10);
  }
  return str;
}

char *itoa(int num)
{
  if (num == 0)
  {
    char *str = (char *) malloc(sizeof(char) * 2);
    *str = '0';
    *(str + 1) = '\0';
    return str;
  }
  if (num == INT_MIN)
  {
    char *str = (char *) malloc(sizeof(char) * 11 + 1);
    str = "-2147483648";
    return str;
  }
  unsigned int is_negative = (num < 0);
  num *= 1 - 2 * is_negative;
  unsigned int num_len = 1 + is_negative;
  int _num = num;
  while (_num > 9)
  {
    num /= 10;
    num_len++;
  }
  char *str = (char *) malloc(sizeof(char) * (num_len + 1));
  if (is_negative)
  {
    *str++ = '-';
  }
  str = (char *) _numtostr(num, str);
  *str = '\0';
  return str - num_len;
}
