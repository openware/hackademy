/*
 * =====================================================================================
 *
 *       Filename:  strdup.c
 *
 *        Created:  16.08.2021 14:44:15
 *       Compiler:  gcc
 *
 *         Author:  vinegod 
 *
 * =====================================================================================
 */

#include <stdlib.h>


char* ft_strdup(char* str) {
	char* s = str;
	int len = 1;
	while(*s++)
		len++;
	char* new_str = (char*)malloc(len + 1);
	while( (*new_str++ = *str++) != '\0' );
	
	return new_str - len + 1;	
}
