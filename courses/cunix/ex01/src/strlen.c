#include <stdio.h>
#include "my_strlen.h" 

int main() {
    const char *test_str = "Hello, World!";
    int length = my_strlen(test_str);

    printf("Length of the string is: %d\n", length);

    return 0;
}
