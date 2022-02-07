#include "vowels.h"

int count_vowels(char *str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
        i++;
    }
    return count;
}