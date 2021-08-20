/*
 * =====================================================================================
 *
 *       Filename:  my_strcmp.c
 *
 *    Description: std strcmp implementation 
 *
 *        Version:  1.0
 *        Created:  08/20/2021 04:53:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Nikita Sazonov (ns), actpohabt.ns@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


int my_strcmp(char *str1, char *str2) {
    char *ch1 = str1, *ch2 = str2;

    while (*(ch1) != '\0' && *(ch2) != '\0') {
        if (*(ch1) != *(ch2)) {
            return *(ch1) - *(ch2);
        }
        ch1++;
        ch2++;
    }

    return *(ch1) - *(ch2);
}
/* -----  end of function my_strcmp  ----- */
