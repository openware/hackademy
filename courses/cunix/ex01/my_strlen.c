#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

unsigned int my_strlen(char *str)
{
	unsigned int count = 0;
	
	for(int i = 0; str[i] != '\0'; i++)
	{
		count++;
	}
	
	return count;
}