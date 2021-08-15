#include <stdlib.h>
char *ft_strsub(char const *s, unsigned int start, size_t len) {
	s += start;
	char *ptr = (char *) malloc (len);
	if (ptr == NULL){
		return NULL;
	}
	for (unsigned int i = 0; i < len; i++){
		ptr[i] = s[i];
	}
	return ptr;
}
