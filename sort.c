#include "data_structures.h"


// sort vector using merge sort
int* ds_sort_merge(int* left_arr, int left_arr_len, int* right_arr, int right_arr_len) {
    int* result = malloc(sizeof(int) * (left_arr_len + right_arr_len));
    int i = 0; int l = 0; int r = 0;

    while (l < left_arr_len && r < right_arr_len) {
        if (left_arr[l] <= right_arr[r]) {
            result[i] = left_arr[l];
            i++; l++;
        } else {
            result[i] = right_arr[r];
            i++; r++;
        }
    }
    while (l < left_arr_len) {
        result[i] = left_arr[l];
        i++; l++;
    }
    while (r < right_arr_len) {
        result[i] = right_arr[r];
        i++; r++;
    }  

    // for (i = 0; i < left_arr_len; i++) {
    //     printf("%d ", left_arr[i]);
    // }
    // printf("\n");
    // for (i = 0; i < right_arr_len; i++) {
    //     printf("%d ", right_arr[i]);
    // }
    // printf("\n\n");
    free(left_arr);
    left_arr = NULL;
    free(right_arr);
    right_arr = NULL;
    return result; 
}

int* ds_sort_mergesort(int* arr, int length) {
    if (length <= 1) return arr;
    int mid = length / 2;
    
    int* left_arr = malloc(sizeof(int) * mid);
    int* right_arr = malloc(sizeof(int) * (length - mid));
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (i < mid) {
            left_arr[i] = arr[i];
        } else {
            right_arr[j] = arr[i];
            j++;
        }
    }
    free(arr);
    arr = NULL;
    left_arr = ds_sort_mergesort(left_arr, mid);
    right_arr = ds_sort_mergesort(right_arr, length - mid);
    
    return ds_sort_merge(left_arr, mid, right_arr, (length - mid));
}

void ds_sort_mergesort_vector(Vector* vec) {
    vec->vec = ds_sort_mergesort(vec->vec, vec->len);
    return;
}

void ds_sort_bubblesort_list(List* list) {
    Node* curr_i = list->head;
    Node* curr_j = list->head->next;

    if (curr_i->content > curr_j->content) {
        int temp = curr_i->content;
        curr_i->content = curr_j->content;
        curr_j->content = temp;
    }

    while(curr_i != NULL) {
        if (curr_i != NULL) curr_j = curr_i->next;
        while (curr_j != NULL) {
            if (curr_i->content > curr_j->content) {
                int temp = curr_i->content;
                curr_i->content = curr_j->content;
                curr_j->content = temp;
            }           
            curr_j = curr_j->next;
        }
        curr_i = curr_i->next;
    }
    return;
}

void ds_sort_bubblesort_vector(Vector* vec) {
    int* arr = vec->vec;
    for (int i = 0; i < vec->len; i++) {
        for (int j = i + 1; j < vec->len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

void ds_sort_quicksort(int arr[], int left, int right) {
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
    ds_sort_quicksort(arr, left, i - 1);
    ds_sort_quicksort(arr, i + 1, right);
}

void ds_sort_quicksort_vector(Vector* vec) {
    ds_sort_quicksort(vec->vec, 0, vec->len - 1);
    return;
}

void ds_sort_quicksort_list(List** list) {
    Vector* vec = ds_vector_new_Vector_from_List(*list);
    ds_sort_quicksort(vec->vec, 0, vec->len - 1); 
    ds_list_destroy(*list);
    List* ll = ds_list_new_List_from_Vector(vec);
    *list = ll;
    ds_vector_destroy(vec);
    return;
}
