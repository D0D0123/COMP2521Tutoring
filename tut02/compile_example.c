#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vowels.h"

#define MAX_LEN 10

int main() {

    // initialises string memory
    char *str = malloc((MAX_LEN + 1) * sizeof(char));

    strcpy(str, "Hello");

    // prints the number of vowels in the string
    printf("%s\n", str);
    printf("num_vowels: %d\n", count_vowels(str));

    free(str);

    return 0;

}