#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}