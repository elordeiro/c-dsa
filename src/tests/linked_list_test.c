#include "test_header.h"

static void test_ds_list_push(List* my_list) {
    printf("\nCalling ds_list_push(...) returns:\n");
    
    srand((u_int32_t) time(NULL));        
    for (int i = 0; i < 20; i++) {
        ds_list_push(my_list, rand() % 1000);
    }
    
    ds_list_print(my_list);
}

static void test_ds_list_peek(List* my_list, int* num) {
    *num = ds_list_peek(my_list);
    printf("\nCalling ds_list_peek() returns: %d\n", *num);
}

static void test_ds_list_pop(List* my_list, int* num) {
    *num = ds_list_pop(my_list);
    printf("\nCalling ds_list_pop() returns: %d\n", *num);
    ds_list_print(my_list);
}

static void test_ds_list_remove(List* my_list, int* num) {
    *num = rand() % 1000;
    printf("\n-- Add %d -- Calling ds_list_remove(%d) returns:\n", *num, *num);
    ds_list_push(my_list, *num);
    ds_list_print(my_list);
    ds_list_remove(my_list, *num);
    ds_list_print(my_list);
}

static void test_ds_list_new_list_from_vector() {
    printf("\nCalling ds_list_new_list_from_Vector() using the following vector returns:\n");
    Vector* vec = ds_vector_new_Vector();
    for (int i = 0; i < 20; i++) {
        ds_vector_push(vec, rand() % 1000);
    }
    ds_vector_print(vec);
    List* new_list = ds_list_new_List_from_Vector(vec);
    ds_list_print(new_list);
    ds_vector_destroy(vec);
    ds_list_destroy(new_list);
}

void test_linked_list() {
    List* my_list = ds_list_new_List();
    int num = 0;
    
    printf("Testing Linked List\n");
    test_ds_list_push(my_list);
    test_ds_list_peek(my_list, &num);
    test_ds_list_pop(my_list, &num);
    test_ds_list_remove(my_list, &num);
    test_ds_list_new_list_from_vector();

    ds_list_destroy(my_list);
    printf("\n---------------------------------------------------------\n\n");
}
