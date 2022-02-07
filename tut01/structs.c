#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    struct student {
        char name[20];
        int age;
        int id;
    };

    typedef struct student *Student; // Student === struct student *

    struct student s1 = {
        .name = "John",
        .age = 20,
        .id = 1
    };




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

}