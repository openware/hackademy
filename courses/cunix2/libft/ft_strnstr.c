char *ft_strnstr(const char *str1, const char *str2, unsigned int n) {
	if (str1 == NULL || str2 == NULL || n == 0){
		return NULL;
	}
	/*int len2 = 0;
	//int hash2 = 0;
	while (*(str2 + len2)){
		//hash2 += *(str2 + len2);
		len2++;
	}
	int len1 = 0
	//int hash1 = 0;
	while (*(str1 + len1)){
		len1++;	
	}
	for(int i = 0; i < len1 - len2*/
	int len = 0;
	while (*(str2 + len)){
		len++;
	}
	int bol = 1;
	char *p = NULL;
	int j;
	++n;
	for (int i = 0; i < (n - len) && bol; i++){
		j = 0;
		while (*(str1 + i + j) == *(str2 + j) ){
			if (j == len - 1){
				p = str1 + i;
				bol = 0;
			}
			if ( !*(str1 + i + j) ){
				bol = 0;
			}
			j++;
		}
	}
	return p;
}
