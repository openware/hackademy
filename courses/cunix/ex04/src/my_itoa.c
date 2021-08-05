#include <stdlib.h>
char* my_itoa(int nmb){
	int count = 0;
	int neg = 0;
	if(nmb < 0){
		neg = 1;
		nmb = -nmb;
		count++;
	}else if(nmb == 0){
		count = 1;
	}
	int num = nmb;
	while(num > 0){
		num /= 10;
		count++;
	}
	
	char *str = (char *) malloc(count+1);
	str[count] = '\0';
	for(int i=0;i<count;i++){
		str[count-i-1] = nmb%10 + '0';
		nmb /= 10;
	}
	if(neg){
		*str = '-';
	}
	return str;
}
