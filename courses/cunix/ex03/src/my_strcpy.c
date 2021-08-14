/*
 * =====================================================================================
 *
 *       Filename:  my_strcpy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.08.2021 19:22:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Den Kalenichenko (), 
 *   Organization:  
 *
 * =====================================================================================
 */

char* my_strcpy(char* dest, const char* src) {

    char* destination = dest;
    while((*dest++ = *src++) != '\0')
        ;
    return destination;
}
