#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int my_atoi(const char *nptr)
{
	 
	bool flag = 0;	
	int i = 0;	
	if(nptr[0] == '-')
		flag = 1;	
	for( i = flag; nptr[i] != '\0'; i++ )
	{
		int k = nptr[i];		
		if(k >= 48 && k <= 57) {	continue;	}
		else {	break;	}
	}	

	if(flag == 1) i-=2; 
	else i--;
	
	int res = 0;	
	for(int j = i; j >= 0; j--)
	{
		int k = nptr[j + flag];
		int poww = 1;
		for(int a = 1; a <= (i - j); a++)	{	poww *= 10;		}
		res += (k - 48) *poww;
	}	

	if (flag == 1)
		return res* (-1);
	else return res;
}