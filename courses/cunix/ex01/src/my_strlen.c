/*
 * =====================================================================================
 *
 *       Filename:  my_strlen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.08.2021 18:57:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

unsigned int my_strlen(char* str) {
    int len = 0;
    while (*str++)
        len++;
    return len;
}


