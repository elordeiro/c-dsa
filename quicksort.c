#include "data_structures.h"

void ds_quicksort_recursive(int arr[], int left, int right) {
    if (right < left) return;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[right];
    arr[right] = temp;
    ds_quicksort_recursive(arr, left, i - 1);
    ds_quicksort_recursive(arr, i + 1, right);
}

void ds_quicksort(Vector* vec) {
    ds_quicksort_recursive(vec->vec, 0, vec->len - 1);
    return;
}
