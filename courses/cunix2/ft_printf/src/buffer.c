#include <stdlib.h>

unsigned int buff_len(char *buff)
{
  unsigned int len = 0;
  while (*buff != '\0')
  {
    buff++;
    len++;
  }
  return len;
}

char *create_buff(const char *format)
{
  unsigned int buff_len = 0;
  while (*format != '%' && *format != '\0')
  {
    format++;
    buff_len++;
  }
  format -= buff_len;

  char *buff = (char *) malloc(sizeof(char) * (buff_len + 1));
  while (*format != '%' && *format != '\0')
  {
    *buff++ = *format++;
  }
  *buff = '\0';
  return (buff - buff_len);
}

const char *next_param(const char *format)
{
  while (*format != '%' && *format != '\0')
  {
      format++;
  }
  return format;
}
