#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_printf(const char format[], ...);

enum format_char {
    FC_STRING = 's',
    FC_INT = 'd',
    FC_INTI = 'i',
    FC_CHARACTER = 'c',
    FC_ITSELF = '%'
};

#define INT_LEN 12

int ft_printf(const char format[], ...) {
    const char* iter = format;
    int char_count = 0;
    va_list args;
    /* start processing the args - format is the last non-stdarg argument so we
     * pass that into the macro to give it a place to start.*/
    va_start(args, format);
    while (*iter) {
        if (*iter == '%') {
            ++iter;
            switch ((enum format_char) * iter) {
                case FC_STRING: {
                    /* extract the string from the args list */
                    const char* string = va_arg(args, char*);
                    /* print the string in a loop */
                    for (; *string; ++string) {
                        putchar(*string);
                        ++char_count;
                    }
                } break;
                case FC_INT: {
                    char outstring[INT_LEN];
                    int outnum = va_arg(args, int);
                    sprintf(outstring, "%d", outnum);
                    char* outiter = outstring;
                    for (; *outiter; ++outiter) {
                        putchar(*outiter);
                        ++char_count;
                    }
                } break;
                case FC_INTI: {
                    char outstring[INT_LEN];
                    int outnum = va_arg(args, int);
                    sprintf(outstring, "%i", outnum);
                    char* outiter = outstring;
                    for (; *outiter; ++outiter) {
                        putchar(*outiter);
                        ++char_count;
                    }
                } break;
                case FC_CHARACTER: {
                    char outstring[INT_LEN];
                    /* use double here as floats passed into stdarg are promoted
                     * to double anyway */
                    char outnum = va_arg(args, int);
                    sprintf(outstring, "%c", outnum);
                    char* outiter = outstring;
                    for (; *outiter; ++outiter) {
                        putchar(*outiter);
                        ++char_count;
                    }
                } break;
                default: {
                    fprintf(stderr, "Error: invalid format specified: %c\n",
                            *iter);
                } break;
                case FC_ITSELF: {
                    break;

                }
            }
            ++iter;
            continue;
        } 
        putchar(*iter);
        ++char_count;
        ++iter;
    }
    return char_count;
}