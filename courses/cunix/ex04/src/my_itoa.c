#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
int kol;
int schet(int n)
{
    if (n/10==0)
      return 1;
   else
     {
        while (n>0) 
         {
            
         n=n/10;
         kol+=1;
         
         }
         return kol;
     }     
 
};
char* my_itoa(int nmb){
 //char *s="";
 int len=schet(nmb);
 char * s = (char*) malloc(len + 1); 
 int i,sign;
 if ((sign = nmb) < 0) /* record sign */
 nmb = -nmb; /* make n positive */
 i = 0;
 do { /* generate digits in reverse order */
 s[i++] = nmb % 10 + '0'; /* get next digit */
 } while ((nmb /= 10) > 0); /* delete it */
 if (sign < 0)
 s[i++] = '-';
 s[i] = '\0';
 //reverse(s); 
 int c, i1, j;
 for (i1 = 0, j = strlen(s)-1; i1 < j; i1++, j--) {
 c = s[i1];
 s[i1] = s[j];
 s[j] = c;
 } 
 return s;
}