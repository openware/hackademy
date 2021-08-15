char *ft_strrchr (const char *str, int ch) {
	int i = -1;
	char *p = NULL;
	do {
		i++;	
		if(str[i] == (char) ch){
			p = str + i;
		}
	} while (str[i] != '\0');
	return p;
}
