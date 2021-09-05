#include <stdlib.h>

div_t div(int numerator, int denominator)
{
  div_t *result = malloc(sizeof(div_t));
  result->quot = numerator / denominator;
  result->rem = numerator % denominator;
  return *result;
}
