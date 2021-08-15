char *ft_strchr (const char *string, int symbol){
	//char ch = (char) symbol;
	int i = 0;
	while (string[i] != (char) symbol && string[i] != '\0'){
		i++;
	}
	/*if (symbol[i] == (char) symbol == '\0'){
		return string+i;
	} else */
	if (string[i] != (char)symbol){
		return NULL;
	}
	return (string+i);
}
