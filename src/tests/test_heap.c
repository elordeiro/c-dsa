#include "test_header.h"

static void test_heap_push(Heap* PQ) {
    printf("\nCalling heap_push(...) returns:\n");
    
    srand((u_int32_t) time(NULL));        
    for (int i = 0; i < 20; i++) {
        heap_push(PQ, rand() % 1000);
    }

    heap_print(PQ);
    heap_print_partial(PQ);
}

static void test_heap_peek(Heap* PQ, int* num) {
    *num = heap_peek(PQ);
    printf("\nCalling heap_peek() returns: %d\n", *num);
}

static void test_heap_pop(Heap* PQ, int* num) {
    printf("\nCalling heap_pop() returns: %d\n", *num);
    *num = heap_pop(PQ);
    heap_print(PQ);
}

static void test_ds_new_heap_from_list() {
    printf("\nCalling heap_new_Heap_from_List() using following list returns:\n");
    List* my_list = ds_new_list();
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 20; i++) {
        list_push(my_list, rand() % 1000);
    }
    Heap* maxPQ = ds_new_heap_from_list(my_list, "max");
    list_print(my_list);
    heap_print(maxPQ);
    heap_destroy(maxPQ);
    list_destroy(my_list);
}

static void test_ds_new_heap_from_tree() {
    printf("\nCalling heap_new_Heap_from_Tree() using following tree returns:\n");
    Tree* my_tree = ds_new_tree();
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 20; i++) {
        tree_add(my_tree, rand() % 1000);
    }
    Heap* maxPQ = ds_new_heap_from_tree(my_tree, "max");
    tree_print(my_tree);
    heap_print(maxPQ);
    heap_destroy(maxPQ);
    tree_destroy(my_tree);
}

void test_heap() {
    Heap* maxPQ = ds_new_heap("max");
    Heap* minPQ = ds_new_heap("min");
    int num = 0;

    printf("Testing Max Heap\n");
    test_heap_push(maxPQ);
    test_heap_peek(maxPQ, &num);
    test_heap_pop(maxPQ, &num);
    printf("\n---------------------------------------------------------\n\n");
    
    printf("Testing Min Heap\n");
    test_heap_push(minPQ);
    test_heap_peek(minPQ, &num);
    test_heap_pop(minPQ, &num);
    printf("\n---------------------------------------------------------\n\n");

    printf("Testing heap_new_Heap_from_List()\n");
    test_ds_new_heap_from_list();

    printf("Testing heap_new_Heap_from_Tree()\n");
    test_ds_new_heap_from_tree();

    heap_destroy(maxPQ);
    heap_destroy(minPQ);
}
