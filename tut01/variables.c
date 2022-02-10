#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {

    int b, c, d;
    d = 0;
    b = c = d;

    d++;

    // printf("d: %d\n", d);
    // printf("c: %d\n", c);
    // printf("b: %d\n", b);

    int *a = &b;
    (*a) += 1;

    // printf("b: %d\n", b);

    char *str1 = "hello";

    // str1[0] = 'b';
    // printf("str1: %s\n", str1);

    char str2[6];
    strcpy(str2, str1);

    // str2[0] = 'b';
    // printf("str2: %s\n", str2);

    char *str3 = str2;

    str3[0] = 'j';
    printf("str3: %s\n", str3);
    printf("str2: %s\n", str2);

}