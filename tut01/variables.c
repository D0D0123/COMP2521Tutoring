#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

    char *immutable_string = "hello"; // "hello" ==> ['h', 'e', 'l', 'l', 'o', '\0']

    // Segfault
    // immutable_string[0] = 'H';

    printf("str: %s\n", str);
    printf("immutable string: %s\n", immutable_string);

    /// Boolean data type ///
    bool boolean = true;
    boolean = false;

    printf("boolean: %d\n", boolean);

    int a, b, c, d, e;
    a = b = c = d = e = 0;

    d++;



    


    /// Pointers ///
    int num = 7;
    int *ptr = NULL;
    ptr = &num;

    // print the value stored in the variable num
    printf("%d\n", num);
    // print the memory address of the pointer that points to num
    printf("%p\n", ptr);
    // print the value stored in the memory address that ptr points to
    // which is the value of num
    printf("%d\n", *ptr);
}