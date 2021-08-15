int ft_strncmp (const char *string1, const char *string2, unsigned int num) {
	int bool = 0;
	for (int i = 0;i < num && !bool; i++){
		if (string1[i] != string2[i] || !string1[i] || !string2[i]){
			if (string1[i] > string2[i]){
				bool = 1;
			} else {
				bool = -1;
			}
		}
	}
	return bool;
}
