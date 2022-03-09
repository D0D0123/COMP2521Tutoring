#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *string);

int main(void) {
    printf("racecar: %d\n", isPalindrome("racecar"));
    printf("hello: %d\n", isPalindrome("hello"));
    printf("kayak: %d\n", isPalindrome("kayak"));
    printf("a: %d\n", isPalindrome("a"));
}


bool isPalindrome(char *string) {
    return false;
}



/* bool isPalindrome(char *string) {
    int length = strlen(string);
    int i = 0;
    int j = length - 1;
    while (i < length/2) {
        if (string[i] != string[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
} */
