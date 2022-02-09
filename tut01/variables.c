#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// constant
#define MAX_SIZE 10

int main() {

    /// Numerical data types /// 
    int integer = 5;
    double dub = 0.3;
    float flt = 0.7;

    /// Character/String data types ///
    char ch = 'a';

    char str[6];
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';
        // OR
    strcpy(str, "hello");

    char *immutable_string = "hello";

    // Segfault
    // immutable_string[0] = 'H';

    /// Boolean data type ///
    bool boolean = true;
    boolean = false;

    // -----------------------------------------------------

    int a, b, c, d;
    d = 0;
    a = b = c = d;

    d++;


    printf("d: %d\n", d);
    printf("c: %d\n", c);
    printf("b: %d\n", b);
    printf("a: %d\n", a);


    


    /// Pointers ///
    int num = 7;
    int *ptr;
    ptr = &num;

    // print the value stored in the variable num
    printf("%d\n", num);
    // print the memory address of the pointer that points to num
    printf("%p\n", ptr);
    // print the value stored in the memory address that ptr points to
    // which is the value of num
    printf("%d\n", *ptr);
}