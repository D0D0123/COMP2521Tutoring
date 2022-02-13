#include <stdio.h>
#include <stdlib.h>

int main() {
    /// Stack allocated arrays ///
    int arr[5];
    arr[0] = 1;

    // arr[5] = 2;

    // Can't have variable length, can't resize



    /// Dynamic/Heap allocated arrays ///

    // allocating an integer array of size 5
    int *nums = malloc(sizeof(int) * 5);
    nums[0] = 1;
    nums[1] = 2;
    printf("nums[1] = %d\n", nums[1]);



    free(nums);
















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