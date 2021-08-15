#include <stdlib.h>
char *ft_strjoin(char const *s1, char const *s2) {
	unsigned int len1 = 0, len2 = 0;
	if (s1 == NULL || s2 == NULL){
		return NULL;
	}
	while (s1[len1] || s2[len2]){
		if (s1[len1]){
			len1++;
		}
		if (s2[len2]){
			len2++;
		}
	}
	char *ptr = (char *) malloc(len1+len2+1);
	if (ptr == NULL){
		return NULL;
	}
	unsigned int condit = (len1 > len2) ? len1 : len2;
	for (int i = 0; i < condit; i++){
		if (i < len1){
			ptr[i] = s1[i];
		}
		if (i < len2){
			ptr[len1+i] = s2[i];
		}
	}
	ptr[len1+len2] = '\0';
	return ptr;
}
