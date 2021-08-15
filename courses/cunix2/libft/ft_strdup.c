#include <stdlib.h>
char *ft_strdup (const char *src) {
	int num = 0;
	while (*(src+num) != '\0'){
		num++;
	}
	if (num == 0){
		return NULL;
	}
	++num;
	char *ptr = (char *) malloc(/*sizeof(src)*/ num);

	if (ptr == NULL){
		exit(1);
	}
	for (int i = 0; i < num; i++){
		ptr[i] = src[i];
	}
	return ptr;
}
