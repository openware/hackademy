#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

char *my_itoa(int nmb)
{
  char *str = malloc(sizeof nmb * CHAR_BIT + 1 + 1);
  sprintf(str, "%d", nmb);
  return str;
}