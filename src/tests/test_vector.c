#include "test_header.h"

static void test_vector_push(Vector* vec) {
    printf("\nCalling vector_push(...) returns:\n");
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 16; i++) {
        vector_push(vec, rand() % 1000);
    }    
    vector_print(vec);
}

static void test_vector_peek(Vector* vec, int *num) {
    *num = vector_peek(vec);
    printf("\nCalling vector_peek() returns: %d\n", *num);
}

static void test_vector_pop(Vector* vec, int* num) {
    *num = vector_pop(vec);
    printf("\nCalling vector_pop() returns: %d\n", *num);
    vector_print(vec);
}

static void test_vector_get_and_set(Vector* vec, int* num) {
    *num = vector_get(vec, 7);
    printf("\nCalling vector_get_content_at_index(7) returns: %d\n", *num);
    vector_set(vec, 7, 77);
    printf("\nvector_set_content_at_index(7, 77) returns: \n");
    vector_print(vec);
}

static void test_vector_remove(Vector* vec, int* num) {
    *num = 77;
    printf("\nCalling vector_remove(%d) returns: \n", *num);
    vector_remove(vec, *num);
    vector_print(vec);
}

static void test_ds_new_vector_from_list() {
    printf("\nCalling vector_new_Vector_from_List() using following list returns: \n");
    srand((u_int32_t) time(NULL));
    List* list = ds_new_list();
    for (int i = 0; i < 20; i++) {
        list_push(list, rand() % 1000);
    }
    Vector* new_vec = ds_new_vector_from_list(list);
    vector_print(new_vec);
    list_print(list);
    list_destroy(list);
    vector_destroy(new_vec);
}

static void test_vector_double_and_halve(Vector* vec) {
    printf("\nPadding the vector till it doubles: ");
    
    srand((u_int32_t) time(NULL));
    while(vec->len < 1025) {
        vector_push(vec, rand() % 1000);
    }
    printf("\nvec->len: %d vec->cap: %d\n", vec->len, vec->cap);
    vector_print_partial(vec);

    printf("\nRemoving close to amount needed to halve it:");
    while(vec->len > 513) {
        vector_pop(vec);
    }
    printf("\nvec->len: %d vec->cap: %d\n", vec->len, vec->cap);
    printf("\n");
    vector_print_partial(vec);
    
    vector_remove(vec, vector_get(vec, vec->len - 1));
    printf("\nCalling vector_remove() returns:");
    printf("\nvec->len: %d vec->cap: %d\n", vec->len, vec->cap);
    vector_print_partial(vec);
}

void test_vector() {
    Vector* vec = ds_new_vector(1024);
    int num = 0;
    
    printf("Testing Vector\n");
    test_vector_push(vec);
    test_vector_peek(vec, &num);
    test_vector_pop(vec, &num);
    test_vector_get_and_set(vec, &num);
    test_vector_remove(vec, &num);
    test_ds_new_vector_from_list();
    test_vector_double_and_halve(vec);
    
    vector_destroy(vec);
    printf("\n---------------------------------------------------------\n\n");
}
