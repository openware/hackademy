int my_strcmp(char *str1, char *str2){
	unsigned int sum1 = 0, sum2 = 0;
	while(*str1 != '\0'){
		sum1 += *str1;
		str1++;
	}
	while(*str2 != '\0'){
		sum2 += *str2;
		str2++;
	}
	if(sum1 == sum2){
		return 0;
	}else if(sum1 > sum2){
		return 1;
	}else{
		return -1;
	}
}
