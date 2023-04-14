#include "test_header.h"

typedef struct {
    double qs_time;
    double ms_time;
} Tuple;

const int VECTOR_SIZE = 1000;
const int LIST_SIZE = 1000;
double execution_time;
clock_t start, end;

static void test_sort_vector_mergesort(Vector* vec1) {
    printf("\nSorting vec1 with mergesort. Vec1 len: %d\n", vec1->len);
    vector_print_partial(vec1);
    start = clock();
    sort_vector_mergesort(vec1);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    vector_print_partial(vec1);
    printf("Mergesort took %lfs\n", execution_time);
}

static void test_sort_vector_quicksort(Vector* vec2) {
    printf("\nSorting vec2 with quicksort. Vec2 len: %d\n", vec2->len);
    vector_print_partial(vec2);
    start = clock();
    sort_vector_quicksort(vec2);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    vector_print_partial(vec2);
    printf("Quicksort took  %lfs\n", execution_time);
}

static void test_sort_vector_bubblesort(Vector* vec3) {
    printf("\nSorting vec3 with bubblesort. Vec3 len: %d\n", vec3->len);
    vector_print_partial(vec3);
    start = clock();
    sort_vector_bubblesort(vec3);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    vector_print_partial(vec3);
    printf("Bubblesort took  %lfs\n", execution_time);
}

static void test_sort_list_mergesort(List** ll1) {
    printf("\nSorting ll1 with mergesort.\n");
    list_print_partial(*ll1);
    start = clock();
    sort_list_mergesort(ll1);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    list_print_partial(*ll1);
    printf("Mergesort took  %lfs\n", execution_time);
}

static void test_sort_list_quicksort(List** ll2) {
    printf("\nSorting ll2 with quicksort.\n");
    list_print_partial(*ll2);
    start = clock();
    sort_list_quicksort(ll2);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    list_print_partial(*ll2);
    printf("Quicksort took  %lfs\n", execution_time);
}

static void test_sort_list_bubblesort(List* ll3) {
    printf("\nSorting ll3 with bubblesort.\n");
    list_print_partial(ll3);
    start = clock();
    sort_list_bubblesort(ll3);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    list_print_partial(ll3);
    printf("Bubblesort took  %lfs\n", execution_time);
}

static double mergesort_no_print(Vector* vec) {
    start = clock();
    sort_vector_mergesort(vec);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    return execution_time;
}

static double quicksort_no_print(Vector* vec) {
    start = clock();
    sort_vector_quicksort(vec);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    return execution_time;
}


static void test_exponential_sort(Tuple* t, int size) {
    Vector* vec1 = ds_new_vector(size);
    Vector* vec2 = ds_new_vector(size);
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < size; i++) {
        vector_push(vec1, rand() % 1000);
        vector_push(vec2, rand() % 1000);
    }

    
    t->ms_time = mergesort_no_print(vec1);
    t->qs_time = quicksort_no_print(vec2);

    vector_destroy(vec1);
    vector_destroy(vec2);
}

void test_sort() {
    srand((u_int32_t) time(NULL)); 
    printf("\nBenchmarking sorting algorithms\n");
    
    printf("\nSorting Vectors\n");
    Vector* vec1 = ds_new_vector(1024);
    Vector* vec2 = ds_new_vector(1024);
    Vector* vec3 = ds_new_vector(1024);
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector_push(vec1, rand() % 1000);
        vector_push(vec2, rand() % 1000);
        vector_push(vec3, rand() % 1000);
    }

    test_sort_vector_mergesort(vec1);
    test_sort_vector_quicksort(vec2);
    test_sort_vector_bubblesort(vec3);

    vector_destroy(vec1);
    vector_destroy(vec2);
    vector_destroy(vec3);

    printf("\nSorting Lists\n");
    List* ll1 = ds_new_list();
    List* ll2 = ds_new_list();
    List* ll3 = ds_new_list();
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < LIST_SIZE; i++) {
        list_push(ll1, rand() % 1000);
        list_push(ll2, rand() % 1000);
        list_push(ll3, rand() % 1000);
    }

    test_sort_list_mergesort(&ll1);
    test_sort_list_quicksort(&ll2);
    test_sort_list_bubblesort(ll3);

    list_destroy(ll1);
    list_destroy(ll2);
    list_destroy(ll3);

    Tuple* t = malloc(sizeof(Tuple));
    printf("\nSorting Exponetially larger vectors\n\n");
    for (int i = 1024; i < 10000000; i = i * 2) {
        test_exponential_sort(t, i);
        printf("Vector size: %d\n", i);
        printf("Mergesort Time: %fs  Quicksort Time: %fs\n", t->ms_time, t->qs_time);
        if (t->qs_time > t->ms_time) {
            printf("Mergesort was faster than Quicksort by: %lfs\n", t->qs_time - t->ms_time);
        } else {
            printf("Quicksort was faster than Mergesort by: %lfs\n", t->ms_time - t->qs_time);
        }
        printf("----------------------------------------------------\n\n");
    }
    free(t);

    // printf("\n---------------------------------------------------------\n\n");
}
