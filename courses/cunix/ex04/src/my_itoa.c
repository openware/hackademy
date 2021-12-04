#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* my_itoa(int nmb)
{	
	int len = 1, arg = 0, tmp = 0;
	bool flag = 0;
	
	if (nmb < 0) { 
		arg = tmp = -nmb;
		flag = 1;
	}
	else {
		arg = tmp = nmb;
	}
	while (arg / 10 > 0)
	{
		len ++;		arg/=10;
	}
	char *str = (char*) malloc(len + flag + 1); 
	if (str==NULL) exit (1);                       
	str[len+flag ]='\0';       
	(flag == 1) ? str[0] = '-': str[0] = ' ';
	for( int i = len - 1 + flag; i >= flag; i--)
	{
		str[i] = tmp % 10 + 48;
		tmp /= 10;
	}
	return str;
}