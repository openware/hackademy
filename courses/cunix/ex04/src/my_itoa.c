#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "test.h"


int length_digit (int number){
    int length = 0;
    for (; number != 0; length++){
        number /= 10;
    }
    if (number <= 0){
        length++;
    }
    return length;
}


char* my_itoa(int nmb){
    int number = nmb;
    int length = length_digit(number);
    char *int_string;


    if(nmb < 0){
        int_string = (char *)malloc(++length);
        int_string[0] = '-';
        nmb = -nmb;
    }
    else if(nmb == 0) {
        int_string = (char *)malloc(2);
        int_string[0] = '0';
        int_string[1] = '\0';
        return int_string;        
    }
    else{
        int_string = (char *)malloc(length);
    }

    int_string[length] = '\0';
    length--;

    while(nmb != 0){
        int_string[length] = (nmb % 10) + '0';
        nmb /= 10;
        length --;
    }


    return int_string;
    
}