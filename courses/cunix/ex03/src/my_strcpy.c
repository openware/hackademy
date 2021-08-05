char *my_strcpy(char *dest, const char *src){
	unsigned int count=0;
	/*if(*src=='\0')
		*dest='\0';
	else*/
	do{
		*(dest+count) = *(src+count);
		count++;
	}while(*(src+count) != '\0');
	*(dest+count) = '\0';
	return dest;
}
