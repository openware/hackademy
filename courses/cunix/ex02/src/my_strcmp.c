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
    while (*(str1) != '\0' && *(str2) != '\0') {
        if (*(str1) != *(str2)) {
            return *(str1) - *(str2);
        }
        str1++;
        str2++;
    }

    return *(str1) - *(str2);
}
/* -----  end of function my_strcmp  ----- */
