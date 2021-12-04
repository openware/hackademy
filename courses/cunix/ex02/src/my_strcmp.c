#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int my_strcmp(char *str1, char *str2)
{
	int i = 0;
	
	while(str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] == str2[i])
		{
			i++;
			continue;
		}
		else if (str1[i] > str2[i])
			return 1;
		else return -1;
	}
	
	return 0;
}