#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSorted(int *a, int n);

int main(int argc, char *argv[]) {
    
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {1, 2, 3, 4, 5, 6, 8, 7, 9, 10};

    printf("isSorted(a, 10): %d\n", isSorted(a, 10));
    printf("isSorted(b, 10): %d\n", isSorted(b, 10));

}


bool isSorted(int *a, int n) {
// 	for elem in list:
//   if curr > next:
//    return false

// return true

	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}

	return true;

}







/*
bool isSorted(int *a, int n) {

	// traverse through the list
		// if n > n + 1 return false
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	
	return true;
}
*/