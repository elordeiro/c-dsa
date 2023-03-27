#include "data_structures.h"

void ds_sort_quicksort_recursive(int arr[], int left, int right) {
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
    ds_sort_quicksort_recursive(arr, left, i - 1);
    ds_sort_quicksort_recursive(arr, i + 1, right);
}

void ds_sort_quicksort_vector(Vector* vec) {
    ds_sort_quicksort_recursive(vec->vec, 0, vec->len - 1);
    return;
}

void ds_sort_quicksort_list(List** list) {
    Vector* vec = ds_vector_new_Vector_from_List(*list);
    ds_sort_quicksort_recursive(vec->vec, 0, vec->len - 1); 
    ds_list_destroy(*list);
    List* ll = ds_list_new_List_from_Vector(vec);
    *list = ll;
    ds_vector_destroy(vec);
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
