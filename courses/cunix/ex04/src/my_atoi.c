/*
 * =====================================================================================
 *
 *       Filename:  my_atoi.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14.08.2021 19:51:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Den Kalenichenko (), 
 *   Organization:  
 *
 * =====================================================================================
 */


int my_atoi(const char* nptr) {
    const char* s = nptr;
    int sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s =='-')
        s++;
    int n = 0;
    for (n = 0; *s <= '9' && *s >= '0'; s++)
            n = 10 * n + (*s - '0');
    return sign * n;

}
