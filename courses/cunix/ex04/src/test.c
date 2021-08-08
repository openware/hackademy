
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

void   test_small()
{
  assert(my_atoi("0") == 0);
  assert(my_atoi("-0") == 0);
  assert(my_atoi("-1") == -1);
  assert(my_atoi("42") == 42);
  assert(my_atoi("-42") == -42);
  assert(my_atoi("1k") == 1);
  assert(my_atoi("123-456") == 123);
}

void           test_long()
{
  assert(my_atoi("123456789") == 123456789);
  assert(my_atoi("2147483647") == 2147483647);
  assert(my_atoi("-2147483648") == -2147483648);
  assert(my_atoi("4294967296") == 0);
  assert(my_atoi("4294967298") == 2);
  assert(my_atoi("ABC") == 0);
  assert(my_atoi("0") == atoi("0"));
}

void           test_verif()
{
  assert(atoi("0") == 0);
  assert(atoi("-0") == 0);
  assert(atoi("-1") == -1);
  assert(atoi("42") == 42);
  assert(atoi("-42") == -42);
  assert(atoi("1k") == 1);
  assert(atoi("123456789") == 123456789);
  assert(atoi("2147483647") == 2147483647);
  assert(atoi("-2147483648") == -2147483648);
  assert(atoi("4294967296") == 0);
  assert(atoi("4294967298") == 2);
  assert(atoi("ABC") == 0);
  assert(atoi("1234QWERTY1234") == 1234);
}

void     test_itoa()
{
  char *str = my_itoa(0);
  assert(strcmp(str, "0") == 0);
  free(str);

  str = my_itoa(1);
  assert(strcmp(str, "1") == 0);
  free(str);

  str = my_itoa(32);
  assert(strcmp(str, "32") == 0);
  free(str);

  str = my_itoa(12345678);
  assert(strcmp(str, "12345678") == 0);
  free(str);
  
  str = my_itoa(-34);
  assert(strcmp(str, "-34") == 0);
  free(str);

  str = my_itoa(-12345678);
  assert(strcmp(str, "-12345678") == 0);
  free(str);

  str = my_itoa(-1234567890);
  assert(strcmp(str, "-1234567890") == 0);
  free(str);
}
int   main()
{
  test_small();
  test_long();
  test_verif();
  test_itoa();
  return(0);
}
