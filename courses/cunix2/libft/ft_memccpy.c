#include <stdlib.h>
void *ft_memccpy(void *dest, const void *src, int ch, unsigned int num) {
	char *p = (char *) dest;
	int size = sizeof(dest);
	if (dest == NULL || src == NULL){
		return dest;
	}
	size = 0;
	int bol = 1;
	while (size < num && bol){
		*(p + size) = *( (char *)src + size);
		if(*( (char *)src + size) == (char) ch){
			bol = 0;
		}
		size++;
	}
	return dest;
}
