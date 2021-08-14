/*
 * =====================================================================================
 *
 *       Filename:  my_itoa.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.08.2021 20:03:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Den Kalenichenko (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>

void my_reverse(char* src, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp;
        temp = src[i];
        src[i] = src[len - i - 1];
        src[len - i - 1] = temp;
    }
}

char* my_itoa(int nmb) {
    char* result = (char*)malloc(32);
    char* number = result;
    int sign;
    if ((sign = nmb) < 0)
        nmb = -nmb;
    int len = 0;
    do {
        *result++ = nmb % 10 + '0';
        len++;
    } while((nmb /= 10) > 0);
    if (sign < 0) {
        len++;
        *result++ = '-';
    }
    *result = '\0';
    my_reverse(number, len);
    return number;

}
