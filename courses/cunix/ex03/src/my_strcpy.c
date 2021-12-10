#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *my_strcpy(char *dest, const char *src)
{
	int i = 0;
	do 
	{
		dest[i] = src[i];
		i++;
		
	} while (src[i - 1] != '\0');
	
	return dest;
}