#include "test_header.h"

static void test_ds_vector_push(Vector* vec) {
    printf("\nCalling ds_vector_push(...) returns:\n");
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 16; i++) {
        ds_vector_push(vec, rand() % 1000);
    }    
    ds_vector_print(vec);
}

static void test_ds_vector_peek(Vector* vec, int *num) {
    *num = ds_vector_peek(vec);
    printf("\nCalling ds_vector_peek() returns: %d\n", *num);
}

static void test_ds_vector_pop(Vector* vec, int* num) {
    *num = ds_vector_pop(vec);
    printf("\nCalling ds_vector_pop() returns: %d\n", *num);
    ds_vector_print(vec);
}

static void test_ds_vector_get_and_set(Vector* vec, int* num) {
    *num = ds_vector_get_content_at_index(vec, 7);
    printf("\nCalling ds_vector_get_content_at_index(7) returns: %d\n", *num);
    ds_vector_set_content_at_index_to(vec, 7, 77);
    printf("\nds_vector_set_content_at_index(7, 77) returns: \n");
    ds_vector_print(vec);
}

static void test_ds_vector_remove(Vector* vec, int* num) {
    *num = 77;
    printf("\nCalling ds_vector_remove(%d) returns: \n", *num);
    ds_vector_remove(vec, *num);
    ds_vector_print(vec);
}

static void test_ds_vector_new_Vector_from_List() {
    printf("\nCalling ds_vector_new_Vector_from_List() using following list returns: \n");
    srand((u_int32_t) time(NULL));
    List* list = ds_list_new_List();
    for (int i = 0; i < 20; i++) {
        ds_list_push(list, rand() % 1000);
    }
    Vector* new_vec = ds_vector_new_Vector_from_List(list);
    ds_vector_print(new_vec);
    ds_list_print(list);
    ds_list_destroy(list);
    ds_vector_destroy(new_vec);
}

static void test_ds_vector_double_and_halve(Vector* vec, int* num) {
    printf("\nvec->len: %d vec->cap: %d", vec->len, vec->cap);
    printf("\nCalling ds_vector_pop() 9 times returns: ");
    for (int i = 0; i < 9; i++) {
        *num = ds_vector_pop(vec);
        printf(" %d ", *num);
    }
    printf("\n");
    ds_vector_print(vec);
    
    printf("\nvec->len: %d vec->cap: %d", vec->len, vec->cap);
    *num = ds_vector_pop(vec);
    printf("\nCalling ds_vector_pop() returns: %d", *num);
    printf("\nvec->len: %d vec->cap: %d\n", vec->len, vec->cap);
    ds_vector_print(vec);
}

void test_vector() {
    Vector* vec = ds_vector_new_Vector();
    int num = 0;
    
    printf("Testing Vector\n");
    test_ds_vector_push(vec);
    test_ds_vector_peek(vec, &num);
    test_ds_vector_pop(vec, &num);
    test_ds_vector_get_and_set(vec, &num);
    test_ds_vector_remove(vec, &num);
    test_ds_vector_new_Vector_from_List();
    test_ds_vector_double_and_halve(vec, &num);
    
    ds_vector_destroy(vec);
    printf("\n---------------------------------------------------------\n\n");
}
