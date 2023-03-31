#include "test_header.h"

static void test_ds_heap_push(Heap* PQ) {
    printf("\nCalling ds_heap_push(...) returns:\n");
    
    srand((u_int32_t) time(NULL));        
    for (int i = 0; i < 20; i++) {
        ds_heap_push(PQ, rand() % 1000);
    }

    ds_heap_print(PQ);
    ds_heap_print_partial(PQ);
}

static void test_ds_heap_peek(Heap* PQ, int* num) {
    *num = ds_heap_peek(PQ);
    printf("\nCalling ds_heap_peek() returns: %d\n", *num);
}

static void test_ds_heap_pop(Heap* PQ, int* num) {
    printf("\nCalling ds_heap_pop() returns: %d\n", *num);
    *num = ds_heap_pop(PQ);
    ds_heap_print(PQ);
}

static void test_ds_heap_new_heap_from_list() {
    printf("\nCalling ds_heap_new_Heap_from_List() using following list returns:\n");
    List* my_list = ds_list_new_List();
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 20; i++) {
        ds_list_push(my_list, rand() % 1000);
    }
    Heap* maxPQ = ds_heap_new_Heap_from_List(my_list, "max");
    ds_list_print(my_list);
    ds_heap_print(maxPQ);
    ds_heap_destroy(maxPQ);
    ds_list_destroy(my_list);
}

static void test_ds_heap_new_Heap_from_Tree() {
    printf("\nCalling ds_heap_new_Heap_from_Tree() using following tree returns:\n");
    Tree* my_tree = ds_tree_new_Tree();
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 20; i++) {
        ds_tree_add_leaf(my_tree, rand() % 1000);
    }
    Heap* maxPQ = ds_heap_new_Heap_from_Tree(my_tree, "max");
    ds_tree_print(my_tree);
    ds_heap_print(maxPQ);
    ds_heap_destroy(maxPQ);
    ds_tree_destroy(my_tree);
}

void test_heap() {
    Heap* maxPQ = ds_heap_new_Heap("max");
    Heap* minPQ = ds_heap_new_Heap("min");
    int num = 0;

    printf("Testing Max Heap\n");
    test_ds_heap_push(maxPQ);
    test_ds_heap_peek(maxPQ, &num);
    test_ds_heap_pop(maxPQ, &num);
    printf("\n---------------------------------------------------------\n\n");
    
    printf("Testing Min Heap\n");
    test_ds_heap_push(minPQ);
    test_ds_heap_peek(minPQ, &num);
    test_ds_heap_pop(minPQ, &num);
    printf("\n---------------------------------------------------------\n\n");

    printf("Testing ds_heap_new_Heap_from_List()\n");
    test_ds_heap_new_heap_from_list();

    printf("Testing ds_heap_new_Heap_from_Tree()\n");
    test_ds_heap_new_Heap_from_Tree();

    ds_heap_destroy(maxPQ);
    ds_heap_destroy(minPQ);
}
