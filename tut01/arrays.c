#include <stdio.h>
#include <stdlib.h>

int *return_stack_array();
int *return_heap_array();


int main() {
    /// Stack allocated arrays ///
    int arr[5];
    arr[0] = 1;

    // Can't resize, only exist within a function's scope



    /// Dynamic/Heap allocated arrays ///

    // allocating an integer array of size 5
    int *nums = malloc(sizeof(int) * 5);
    nums[0] = 1;
    nums[1] = 2;
    printf("nums[1] = %d\n", nums[1]);

    nums = realloc(nums, sizeof(int) * 10);
    nums[8] = 6;
    printf("nums[8] = %d\n", nums[8]);



    free(nums);

    int* arr_p;

    // undefined behaviour
    // arr_p = return_stack_array();
    // printf("%d\n", arr_p[9]);

    // correct
    arr_p = return_heap_array();
    printf("arr_p[9] = %d\n", arr_p[9]);
    free(arr_p);


    /*
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
    // printf("arr2d[2][3] = %d\n", arr2d[2][3]);

    // free the memory
    for (int i = 0; i < 5; i++) {
        free(arr2d[i]);
    }
    free(arr2d);
    */
}

// invalid return 
// int *return_stack_array() {
//   int arr[10];
//   for (int i = 0; i < 10; i++) {
//     arr[i] = i;
//   }
//   return arr;
// }

// valid return
int *return_heap_array() {
  int *arr = malloc(10 * sizeof(int));
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  return arr;
}