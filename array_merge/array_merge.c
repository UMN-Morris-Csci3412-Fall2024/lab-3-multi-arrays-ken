#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int *array_merge(int num_arrays, int *sizes, int **values){
    // Calculate the total size of all sub-arrays in `values`
    int total_size = 0;
    for (int i = 0; i < num_arrays; i++){
        total_size += sizes[i];
    }

    // Collect unique values from all sub-arrays in `values`
    int *temp = (int *)calloc(total_size, sizeof(int));
    int temp_size = 0;

    for (int i = 0; i < num_arrays; i++){
        for (int j = 0; j < sizes[i]; j++){
            int value = values[i][j];
            int is_unique = 1;
            for (int k = 0; k < temp_size; k++){
                if (temp[k] == value){
                    is_unique = 0;
                    break;
                }
            }
            if (is_unique){
                temp[temp_size++] = value;
            }
        }
    }

    // Sort the collected unique values using merge sort
    mergesort(temp_size, temp);

    // Prepare the result array with the count of unique values as the first element
    int *result = (int *)calloc(temp_size + 1, sizeof(int));
    result[0] = temp_size;
    for (int i = 0; i < temp_size; i++){
        result[i + 1] = temp[i];
    }

    // Free any unused memory to avoid memory leaks
    free(temp);

    // Return the result array
    return result;
}


/*
Array Sort: Function to merge arrays into a single sorted array of unique values.

Step 1: Collect unique values from all sub-arrays in `values`
Step 2: Sort the collected unique values using merge sort
Step 3: Prepare the result array with the count of unique values as the first element
Step 4: Free any unused memory to avoid memory leaks
Step 5: Return the result array
*/
