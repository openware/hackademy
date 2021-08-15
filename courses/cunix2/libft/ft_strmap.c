#include <stdlib.h>
char *ft_strmap(char const *s, char (*f)(char)) {
	unsigned int count = 0;
	while (*(s+count)){
		count++;
	}
	char *ptr = (char *) malloc(++count);
	if (ptr == NULL){
		return NULL;
	}
	for (unsigned int i = 0; i < count; i++){
		ptr[i] = f(s[i]);
	}
	return ptr;
}
