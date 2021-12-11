#include "test.h"



int my_strcmp(char *str1, char *str2){
    unsigned int index;

    // Looping over the strings in order to compare them(till terminating null character '\0')
    for (index = 0; str1[index] != '\0' && str2[index] != '\0'; index++){
        // It will return 1 if str1 is greater than str2
        if (str1[index] > str2[index]){
            return 1;
        }
        // it will return -1 if str2 is greater than str1
        else if (str2[index] > str1[index]){
            return -1;
        }
    }
    // it will return 0 if str1 is equal to str2
    return 0;
}