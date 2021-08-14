/*
 * =====================================================================================
 *
 *       Filename:  my_puts.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.08.2021 20:55:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Den Kalenichenko (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>

int my_puts(const char* s) {
    if (s) {
        int len = 0;
        while (*s != '\0') {
            write(1, s++, 1);
            len++;
        }
        write(1, "\n", 1);
        return len;
    }
    else
        return -1;

}
