#include <stdio.h>
#include <stdlib.h>

int main() {
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
}