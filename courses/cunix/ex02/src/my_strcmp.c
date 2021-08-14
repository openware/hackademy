/*
 * =====================================================================================
 *
 *       Filename:  my_strcmp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.08.2021 19:05:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


int my_strcmp(char* str1, char* str2) {
    while(*str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 < *str2 ? -1 : 1;
}
