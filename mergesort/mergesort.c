#include "mergesort.h"
#include <stdlib.h> // Needed for calloc and free

// Remember that a key goal here is to learn to use
// `malloc/calloc` and `free`, so make sure you explicitly
// allocate any new arrays that you need, even if you
// might not strictly need to.

void mergesort(int size, int values[]){
    // Base case: if the array has fewer than 2 elements, it's already sorted.
    if (size <= 1){
        return;
    }

    // Split the array into two halves.
    int mid = size / 2;
    int *left = (int*)calloc(mid, sizeof(int));         // Allocate memory for the left half.
    int *right = (int*)calloc(size - mid, sizeof(int)); // Allocate memory for the right half.
    // left and right threw errors w/o casting to (int*)

    // Copy data to the left and right arrays
    for (int i = 0; i < mid; i++){
        left[i] = values[i];
    }
    for (int i = mid; i < size; i++){
        right[i - mid] = values[i];
    }

    // Recursively sort each half.
    mergesort(mid, left);
    mergesort(size - mid, right);

    // Merge the two halves back together.
    merge(size, values, left, right);

    // Free the memory allocated for left and right arrays.
    free(left);
    free(right);
}

void merge(int size, int values[], int left[], int right[]){
    int mid = size / 2;
    int left_size = mid;
    int right_size = size - mid;

    int i = 0, j = 0, k = 0;

    // Compare elements from left and right arrays and merge them into values array.
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            values[k++] = left[i++];
        } else {
            values[k++] = right[j++];
        }
    }

    // Copy the remaining elements of left[]
    while (i < left_size) {
        values[k++] = left[i++];
    }

    // Copy the remaining elements of right[]
    while (j < right_size) {
        values[k++] = right[j++];
    }
}

/*
Mergesort pseudocode:
    1. If the array has fewer than 2 elements, return.
    2. Otherwise, split the array into two halves.
    3. Recursively sort each half.
    4. Merge the two halves back together.

    List mergesort(List inlist) {
        if (inlist.length() <= 1)
            return inlist;;
        List L1 = half of the items from inlist;
        List L2 = other half of the items from inlist;
        return merge(mergesort(L1), mergesort(L2));
}

    List merge(List L1, List L2) {
    List answer = new List();
    while (L1 != NULL || L2 != NULL) {
        if (L1 == NULL) { // Done L1
        answer.append(L2);
        L2 = NULL;
        }
        else if (L2 == NULL) { // Done L2
        answer.append(L1);
        L1 = NULL;
        }
        else if (L1.value() <= L2.value()) {
        answer.append(L1.value());
        L1 = L1.next();
        }
        else {
        answer.append(L2.value());
        L2 = L2.next();
        }
    }
    return answer;
    }
*/
