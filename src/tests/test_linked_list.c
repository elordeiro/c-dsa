#include "test_header.h"


static void test_list_push(List* my_list) {
    printf("\nCalling list_push(...) returns:\n");
    
    srand((u_int32_t) time(NULL));        
    for (int i = 0; i < 20; i++) {
        list_push(my_list, rand() % 1000);
    }
    
    list_print(my_list);
}

static void test_list_peek(List* my_list, int* num) {
    *num = list_peek(my_list);
    printf("\nCalling list_peek() returns: %d\n", *num);
}

static void test_list_pop(List* my_list, int* num) {
    *num = list_pop(my_list);
    printf("\nCalling list_pop() returns: %d\n", *num);
    list_print(my_list);
}

static void test_list_remove(List* my_list, int* num) {
    *num = rand() % 1000;
    printf("\n-- Add %d -- Calling list_remove(%d) returns:\n", *num, *num);
    list_push(my_list, *num);
    list_print(my_list);
    list_remove(my_list, *num);
    list_print(my_list);
}

static void test_ds_new_list_from_vec() {
    printf("\nCalling list_new_list_from_Vector() using the following vector returns:\n");
    Vector* vec = ds_new_vector(1024);
    for (int i = 0; i < 20; i++) {
        vector_push(vec, rand() % 1000);
    }
    vector_print(vec);
    List* new_list = ds_new_list_from_vec(vec);
    list_print(new_list);
    vector_destroy(vec);
    list_destroy(new_list);
}


void test_linked_list() {
    List* my_list = ds_new_list();
    int num = 0;
    
    printf("Testing Linked List\n");
    test_list_push(my_list);
    test_list_peek(my_list, &num);
    test_list_pop(my_list, &num);
    test_list_remove(my_list, &num);
    test_ds_new_list_from_vec();

    list_destroy(my_list);
    printf("\n---------------------------------------------------------\n\n");
}
