int ft_isalpha(int ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
		return 1;
	} else {
		return 0;
	}
}
