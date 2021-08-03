
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "test.h"

void   test_small()
{
  assert(my_strcmp("", "") == 0);
  assert(my_strcmp("A", "A") == 0);
  assert(my_strcmp("AB", "AB") == 0);
  assert(my_strcmp("AB", "AC") == -1);
  assert(my_strcmp("AB", "AA") == 1);
  assert(my_strcmp("AB", "AD") == -1);
}

void   test_long()
{
  assert(my_strcmp("HELLO WORLD", "HELLA WORLD") > 0);
  assert(my_strcmp("HELLO WORLD", "HELL WORLD") == 1);
}

int   main()
{
  test_small();
  test_long();
  return(0);
}
