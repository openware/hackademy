#include <stdlib.h>
void *ft_memcpy(void *dest, const void *src, unsigned int num) {
	char *p = (char *) dest;
	//int size = sizeof(destptr);
	if (/*(sizeof(dest)*8 < num) ||*/ dest == NULL || src == NULL){
		return dest;
	}
	while (num){
		num--;
		*(p + num) = *( (char *)src + num);
	}
	return dest;
}
