#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

/*
 * This function takes in an integer between 0 - 6
 * and returns the corresponding day of the week.
 */
char *numToDay(int n);
/*
 * This function takes in a character
 * and prints whether it is a consonant or vowel.
 */ 
void vowelOrConsonant(char ch);

int main(int argc, char *argv[]) {
    int i = 4;
    printf("day %d: %s\n", i, numToDay(4));

    vowelOrConsonant('a');
    vowelOrConsonant('g');

}

char *numToDay(int n) {
	assert(0 <= n && n <= 6);
	char *day;
	if (n == 0) {
		day = "Sun";
	} else if (n == 1) {
		day = "Mon";
	} else if (n == 2) {
		day = "Tue";
	} else if (n == 3) {
		day = "Wed";
	} else if (n == 4) {
		day = "Thu";
	} else if (n == 5) {
		day = "Fri";
	} else if (n == 6) {
		day = "Sat";
	}
	return day;
}




/*
char *numToDay(int n) {
	assert(0 <= n && n <= 6);
	char *day;
	switch (n) {
		case 0: day = "Sun"; break;
		case 1: day = "Mon"; break;
		case 2: day = "Tue"; break;
		case 3: day = "Wed"; break;
		case 4: day = "Thu"; break;
		case 5: day = "Fri"; break;
		case 6: day = "Sat"; break;
	}
	return day;
}
*/

/*
char *numToDay(int n) {
	assert(0 <= n && n <= 6);
	switch (n) {
		case 0:  return "Sun";
		case 1:  return "Mon";
		case 2:  return "Tue";
		case 3:  return "Wed";
		case 4:  return "Thu";
		case 5:  return "Fri";
		case 6:  return "Sat";
		default: return "???";
	}
}
*/

void vowelOrConsonant(char ch) {
    assert(islower(ch));
    switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c: vowel\n", ch); break;
        default:
            printf("%c: consonant\n", ch); break;
    }
}






void vowelOrConsonant(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
	    printf("vowel");
    } else {
        printf("consonant");
    }
}