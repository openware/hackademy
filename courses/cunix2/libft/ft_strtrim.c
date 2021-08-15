#include <stdlib.h>
char *ft_strtrim(char const *s) {
	if (s == NULL){
		return NULL;
	}
	unsigned int beg = 0, end, len = 0;
	while (s[len]){
		len++;
	}
	while ((s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t') && beg < len){
		beg++;
	}
	end = len-1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end){
		end--;
	}
	end++;
	char *ptr = (char *) malloc(end - beg + 1);
	if (ptr == NULL){
		return NULL;
	}
	for (int i = 0; i < end - beg; i++){
		ptr[i] = s[i + beg];
	}
	ptr[end - beg] = '\0';
	return ptr;
}
