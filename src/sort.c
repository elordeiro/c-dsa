#include "data_structures.h"

// sort vector using merge sort
static int* merge(int* left_arr, int left_arr_len, int* right_arr, int right_arr_len) {
    int* result = malloc(sizeof(int) * (u_int64_t) (left_arr_len + right_arr_len));
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

    free(left_arr);
    left_arr = NULL;
    free(right_arr);
    right_arr = NULL;
    return result; 
}

static int* ds_mergesort(int* arr, int length) {
    if (length <= 1) return arr;
    int mid = length / 2;
    
    int* left_arr = malloc(sizeof(int) * (u_int64_t) mid);
    int* right_arr = malloc(sizeof(int) * (u_int64_t) (length - mid));
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
    left_arr = ds_mergesort(left_arr, mid);
    right_arr = ds_mergesort(right_arr, length - mid);
    
    return merge(left_arr, mid, right_arr, (length - mid));
}

void sort_vector_mergesort(Vector* vec) {
    vec->vec = ds_mergesort(vec->vec, vec->len);
    return;
}

void sort_list_mergesort(List** list) {
    Vector* vec = ds_new_vector_from_list(*list);
    sort_vector_mergesort(vec); 
    list_destroy(*list);
    List* ll = ds_new_list_from_vec(vec);
    *list = ll;
    vector_destroy(vec);
    return;
}

void sort_list_bubblesort(List* list) {
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

void sort_vector_bubblesort(Vector* vec) {
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

static void quicksort(int arr[], int left, int right) {
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
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

void sort_vector_quicksort(Vector* vec) {
    quicksort(vec->vec, 0, vec->len - 1);
    return;
}

void sort_list_quicksort(List** list) {
    Vector* vec = ds_new_vector_from_list(*list);
    quicksort(vec->vec, 0, vec->len - 1); 
    list_destroy(*list);
    List* ll = ds_new_list_from_vec(vec);
    *list = ll;
    vector_destroy(vec);
    return;
}
