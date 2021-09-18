#include "test.h"
#include <string.h>



char *my_strcpy(char *dest, const char *src){
int i;
 i = 0;
 while ((dest[i] = src[i]) != '\0')
 i++; 

//char *a=strcpy(dest,src);
return dest;
}