int my_atoi(const char *nptr){
	int count = 0;
	int neg = 0;
	if(*nptr == '-'){
		neg = 1;
		nptr++;
	}
	while(*(nptr+count) >= '0' && *(nptr+count) <= '9'){
		count++;
	}
	int sum = 0;

	for(int i=0;i < count;i++){
		sum *= 10;
		sum += (int)(*(nptr+i) - '0');
	}
	if(neg){
		sum *= -1;
	}
	return sum;
}
