#include <stdlib.h>
void *ft_memset(void *destination, int ch, unsigned int n) {
	unsigned char* p = destination;
	while(n--){
		*p = (unsigned char) ch;
		p++;
	}
	return destination;
}
