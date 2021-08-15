#include <stdlib.h>
int ft_memcmp(const void *buf1, const void *buf2, unsigned int count) {
	int *ptr1 = (int *)buf1;
	int *ptr2 = (int *)buf2;
	while (count-- && *ptr1 == *ptr2){
		ptr1++;
		ptr2++;
	}
	if (count){
		if (*ptr1 > *ptr2){
			return 1;
		} else {
			return -1;
		}
	}
	return 0;
}
