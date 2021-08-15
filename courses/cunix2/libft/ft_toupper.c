int ft_toupper(int ch) {
	if (ch >= 'a' && ch <= 'z'){
		ch += ('A' - 'a');
	}
	return (int) ch;
}
