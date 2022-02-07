#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "starter.h"

int sumOfThree(int a, int b, int c);
void addToInt(int x);
void addToIntByRef(int *x);

int main(int argc, char *argv[]) {
    int a, b, c, d, e;
    a = b = c = d = e = 0;

    c++;

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

/// Boolean data type ///
    bool boolean = true;
    boolean = false;

    printf("boolean: %d\n", boolean);

/// Ternary operator ///
    int age = 5;
    int fee = 0;

    if (age > 18) {
        fee = 100;
    } else {
        fee = 50;
    }

    // variable = (condition) ? value_if_true : value_if_false;
    fee = (age > 18) ? 100 : 50;


/// For loop ///
    int i = 0;
    while(i < 10) {
        printf("i: %d\n", i);
        i++;
    }

    printf("normal for loop \n");
    for(int i = 0; i < 10; i++) {
        printf("i: %d\n", i);
    }

    printf("for loop with break \n");
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
        printf("i: %d\n", i);
    }

    printf("for loop with continue \n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("i: %d\n", i);
    }   

/// Functions ///
    printf("sum of 1 + 2 + 3 = %d\n", sumOfThree(1, 2, 3));
    printf("product of 1 * 2 * 3 = %d\n", productOfThree(1, 2, 3));


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

/// Stack allocated arrays ///
    int arr[5];
    arr[0] = 1;

    // Segmentation fault
    // arr[5] = 2;

/// Dynamic arrays ///

    // allocating an integer array of size 5
    int *dyn_arr = malloc(sizeof(int) * 5);
    dyn_arr[0] = 1;
    dyn_arr[1] = 2;
    printf("dyn_arr[1] = %d\n", dyn_arr[1]);
    free(dyn_arr);

/// 2D Dynamic arrays ///

    // allocating a 2D integer array of size 5x5
    int **arr2d = malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++) {
        arr2d[i] = malloc(sizeof(int) * 5);
    }

    // fill the array with values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr2d[i][j] = i * j;
        }
    }

    // print an element of the array
    printf("arr2d[2][3] = %d\n", arr2d[2][3]);

    // free the memory
    for (int i = 0; i < 5; i++) {
        free(arr2d[i]);
    }
    free(arr2d);

/// Structs and Memory Leakage ///
    struct student {
        char name[20];
        int age;
        int id;
    };

    struct student s1 = {
        .name = "John",
        .age = 20,
        .id = 1
    };

    typedef struct student *Student; // Student === struct student *

    // which of these is correct? which of these are incorrect?

    Student s2 = malloc(sizeof(struct student));
    Student s3 = malloc(sizeof(Student *));
    Student s4 = malloc(sizeof(Student));
    Student s5 = malloc(sizeof(*s5));

    printf("size of struct student: %lu\n", sizeof(struct student));
    printf("size of struct Student *: %lu\n", sizeof(Student *));
    printf("size of struct Student: %lu\n", sizeof(Student));
    printf("size of struct *s5: %lu\n", sizeof(*s5));

    free(s2);
    // free(s3);
    // free(s4);
    free(s5);

/// Variable Scope and Passing by Reference ///
    int x = 5;
    addToInt(x);
    printf("x = %d\n", x);

    addToIntByRef(&x);
    printf("x = %d\n", x);

}

int sumOfThree(int a, int b, int c) {
    return a + b + c;
}

int productOfThree(int a, int b, int c) {
    return a * b * c;
}

void addToInt(int x) {
    x += 1;
}

void addToIntByRef(int *x) {
    *x += 1;
}
