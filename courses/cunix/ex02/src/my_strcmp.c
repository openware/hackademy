#include "test.h"
#include <string.h>

int my_strcmp(char *str1, char *str2){
    int a;
    int i=0;
    for (i = 0; str1[i] == str2[i]; i++)
    if (str1[i] == '\0')
    return 0;
 //return s[i] - t[i]; 
    a=str1[i]-str2[i];

    if(a>0){
        a=1;
    } else if (a<0){
        a=-1;
    } else {a=0;}
    return a;
}
/*int my_strcmp(char *str1, char *str2)
 {
 int i;
 for (i = 0; str1[i] == str2[i]; i++)
 if (str1[i] == '\0')
 return 0;
 return str1[i] - str2[i];
 }*/