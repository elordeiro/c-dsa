#include "test_header.h"

const int VECTOR_SIZE = 1000;
const int LIST_SIZE = 1000;
double qs = 0;
double ms = 0;
double execution_time;
clock_t start, end;

static void test_mergesort_vectors(Vector* vec1) {
    printf("\nSorting vec1 with mergesort. Vec1 len: %d\n", vec1->len);
    ds_vector_print_partial(vec1);
    start = clock();
    ds_sort_mergesort_vector(vec1);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_vector_print_partial(vec1);
    printf("Mergesort took %lfs\n", execution_time);
}

static void test_quicksort_vector(Vector* vec2) {
    printf("\nSorting vec2 with quicksort. Vec2 len: %d\n", vec2->len);
    ds_vector_print_partial(vec2);
    start = clock();
    ds_sort_quicksort_vector(vec2);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_vector_print_partial(vec2);
    printf("Quicksort took  %lfs\n", execution_time);
}

static void test_bubblesort_vector(Vector* vec3) {
    printf("\nSorting vec3 with bubblesort. Vec3 len: %d\n", vec3->len);
    ds_vector_print_partial(vec3);
    start = clock();
    ds_sort_bubblesort_vector(vec3);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_vector_print_partial(vec3);
    printf("Bubblesort took  %lfs\n", execution_time);
}

static void test_mergesort_list(List** ll1) {
    printf("\nSorting ll1 with mergesort.\n");
    ds_list_print_partial(*ll1);
    start = clock();
    ds_sort_mergesort_list(ll1);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_list_print_partial(*ll1);
    printf("Mergesort took  %lfs\n", execution_time);
}

static void test_quicksort_list(List** ll2) {
    printf("\nSorting ll2 with quicksort.\n");
    ds_list_print_partial(*ll2);
    start = clock();
    ds_sort_quicksort_list(ll2);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_list_print_partial(*ll2);
    printf("Quicksort took  %lfs\n", execution_time);
}

static void test_bubblesort_list(List* ll3) {
    printf("\nSorting ll3 with bubblesort.\n");
    ds_list_print_partial(ll3);
    start = clock();
    ds_sort_bubblesort_list(ll3);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_list_print_partial(ll3);
    printf("Bubblesort took  %lfs\n", execution_time);
}

static double test_mergesort_vector_no_print(Vector* vec) {
    start = clock();
    ds_sort_mergesort_vector(vec);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    return execution_time;
}

static double test_quicksort_vector_no_print(Vector* vec) {
    start = clock();
    ds_sort_quicksort_vector(vec);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    return execution_time;
}


static void test_exponential_sort(int size) {
    Vector* vec1 = ds_vector_new_Vector();
    Vector* vec2 = ds_vector_new_Vector();
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < size; i++) {
        ds_vector_push(vec1, rand() % 1000);
        ds_vector_push(vec2, rand() % 1000);
    }

    ms = test_mergesort_vector_no_print(vec1);
    qs = test_quicksort_vector_no_print(vec2);

    ds_vector_destroy(vec1);
    ds_vector_destroy(vec2);
}

void test_sort() {
    srand((u_int32_t) time(NULL)); 
    printf("\nBenchmarking sorting algorithms\n");
    
    printf("\nSorting Vectors\n");
    Vector* vec1 = ds_vector_new_Vector();
    Vector* vec2 = ds_vector_new_Vector();
    Vector* vec3 = ds_vector_new_Vector();
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        ds_vector_push(vec1, rand() % 1000);
        ds_vector_push(vec2, rand() % 1000);
        ds_vector_push(vec3, rand() % 1000);
    }

    test_mergesort_vectors(vec1);
    test_quicksort_vector(vec2);
    test_bubblesort_vector(vec3);

    ds_vector_destroy(vec1);
    ds_vector_destroy(vec2);
    ds_vector_destroy(vec3);

    printf("\nSorting Lists\n");
    List* ll1 = ds_list_new_List();
    List* ll2 = ds_list_new_List();
    List* ll3 = ds_list_new_List();
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < LIST_SIZE; i++) {
        ds_list_push(ll1, rand() % 1000);
        ds_list_push(ll2, rand() % 1000);
        ds_list_push(ll3, rand() % 1000);
    }

    test_mergesort_list(&ll1);
    test_quicksort_list(&ll2);
    test_bubblesort_list(ll3);

    ds_list_destroy(ll1);
    ds_list_destroy(ll2);
    ds_list_destroy(ll3);

    printf("\nSorting Exponetially larger vectors\n\n");
    for (int i = 1024; i < 10000000; i = i * 2) {
        test_exponential_sort(i);
        printf("Vector size: %d\n", i);
        printf("Mergesort Time: %f  Quicksort Time: %f\n", ms, qs);
        if (qs > ms) {
            printf("Mergesort was faster than Quicksort by: %lfs\n", qs - ms);
        } else {
            printf("Quicksort was faster than Mergesort by: %lfs\n", ms - qs);
        }
        printf("----------------------------------------------------\n\n");
    }
    // printf("\n---------------------------------------------------------\n\n");
}
