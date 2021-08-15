#include <stdlib.h>
void *ft_memchr(const void *arr, int c, unsigned int n) {
	if (arr == NULL){
		return NULL;
	}
	char *p = (char *)arr;
	while (n-- && *p != (char) c){
		p++;
	}
	return p;
}
