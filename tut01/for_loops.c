#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


    int i = 0;
    while(i < 10) {
        printf("i: %d\n", i);
        i++;
    }

    /* 
    INITIALIZATION
    while (CONDITION) {
        // do something
        ITERATION
    }
    */

    /* 
    for (INITIALIZATION; CONDITION; ITERATION) {
        // do something
    }
    */

    printf("normal for loop \n");
    // how do we convert the while loop to a for loop?
    int k;
    for (k = 0; k < 10; k++) {
        printf("k: %d\n", k);
    }

    
    printf("for loop with break \n");
    for (int i = 0; i < 10; i++) {
        if (i == 5) 
            break;
        printf("i: %d\n", i);
    }

    printf("for loop with continue \n");
    for (int i = 0; i < 10; i++) {
        if (i == 7)
            continue;
        printf("i: %d\n", i);
    }
}