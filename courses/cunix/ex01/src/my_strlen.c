#include "test.h"
#include <string.h>

int unsigned my_strlen(char *str){
    int i=0;
    while (str[i] != '\0')
    ++i;
    return i; 
}