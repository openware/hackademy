int ft_tolower(int ch) {
	if (ch >= 'A' && ch <= 'Z'){
		ch -= ('A' - 'a');
	}
	return (int) ch;
}
