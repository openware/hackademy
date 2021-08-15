#include <stdlib.h>
char **ft_strsplit(char const *s, char c) {
	if (s == NULL){
		return /*&*/ NULL;
	}
	char **arraystr;
	unsigned int num = 0;
	unsigned int len = 0,beg = 0, end;
	while (s[len]){
		len++;
	}
	len++;
	while (beg < len){
		while (s[beg] == c && beg < len){
			beg++;
		}
		if (beg < len){
			num++;
			end = beg;
			while (s[end] != c && end < len){
				end++;
			}
			beg = end;
		}
	}
	arraystr = (char **) malloc(num * sizeof(char *));
	//int i = 0;
	num = beg = end = 0;
	while (/*i*/beg < len){
		while (s[beg] == c && beg < len){
			beg++;
		}
		end = beg;
		while (s[end] != c && end < len){
			end++;
		}
		char *ptr = (char *) malloc(end - beg + 1);
		if (ptr == NULL){
			return NULL;
		}
		for (unsigned int i = 0; i < end - beg; i++){
			ptr[i] = s[i + beg];
		}
		ptr[end - beg] = '\0';
		*(arraystr + num) = ptr;
		num++;
		beg = end;
	}
	*(arraystr + num) = (char *) malloc(1);
	**(arraystr + num) = '\0';
	return arraystr;
}
