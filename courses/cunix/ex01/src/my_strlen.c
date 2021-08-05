unsigned int my_strlen(char *str){
	unsigned int num=0;
	//char ch;
	while(*str!='\0'){
		num++;
		str++;
	}
	return num;
}
