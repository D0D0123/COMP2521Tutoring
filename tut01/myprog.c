#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("number of arguments: %d\n", argc);
    int i = 0;
    while (i < argc) {
        printf("argv[%d]: %s\n", i, argv[i]);
        i++;
    }
}

// ./myprog hello there, 'John Shepherd' > myFile