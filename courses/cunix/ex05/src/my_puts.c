#include <stdio.h>
int my_puts(const char *s){
	char ch;
	while((ch=*s)!='\0'){
		s++;
		putchar(ch);
	}
	putchar('\n');
	return 0;
}

