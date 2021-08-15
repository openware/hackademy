char *ft_strstr(const char *str1, const char *str2) {
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
	if (str1 == NULL || str2 == NULL){
		return NULL;
	}
	int len1 = 0;
	int len2 = 0;
	while (*(str1 + len1)){
		len1++;
	}
	while (*(str2 + len2)){
		len2++;
	}
	int bol = 1;
	char *p = NULL;
	int j;
	for (int i = 0; i < (len1 - len2) && bol; i++){
		j = 0;
		while (*(str1 + i + j) == *(str2 + j)){
			if (j == len2 - 1){
				p = str1 + i;
				bol = 0;
			}
			j++;
		}
	}
	return p;
}
