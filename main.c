#include "data_structures.h"

// #define TEST_Heap 1
// #define TEST_LINKED_LIST 1
// #define TEST_VECTOR 1
// #define TEST_BINARY_TREE 1
#define TEST_QUICKSORT 1

int main () {
    srand(time(NULL));
    
    #ifdef TEST_Heap
    printf("Testing Max Heap\n");
    // 1)
    printf("\nCalling ds_heap_push(...) returns:\n");
    Heap* maxPQ = ds_heap_new_Heap("max");
    for (int i = 0; i < 10; i++) {
        ds_heap_push(maxPQ, rand() % 1000);
    }
    ds_heap_print(maxPQ);
    
    // 2)
    int max = ds_heap_peek(maxPQ);
    printf("\nCalling ds_heap_peek() returns: %d\n", max);
    
    // 3)
    max = ds_heap_pop(maxPQ);
    printf("\nCalling ds_heap_pop() returns: %d\n", max);
    ds_heap_print(maxPQ);
    
    printf("\n---------------------------------------------------------\n\n");
    
    printf("Testing Min Heap\n");
    
    // 1)
    printf("\nCalling ds_heap_push(...) returns:\n");
    Heap* minPQ = ds_heap_new_Heap("min");
    for (int i = 0; i < 10; i++) {
        ds_heap_push(minPQ, rand() % 1000);
    }
    ds_heap_print(minPQ);
    
    // 2)
    int min = ds_heap_peek(minPQ);
    printf("\nCalling ds_heap_peek() returns: %d\n", min);
    
    // 3)
    min = ds_heap_pop(minPQ);
    printf("\nCalling ds_heap_pop() returns: %d\n", min);
    ds_heap_print(minPQ);

    #endif

    printf("\n---------------------------------------------------------\n\n");
    
    #if TEST_LINKED_LIST
    printf("Testing Linked List\n");
    
    // 1)
    printf("\nCalling ds_list_push(...) returns:\n");
    List* my_list = ds_list_new_List();
    ds_list_push(my_list, 1000);
    ds_list_push(my_list, 100);
    ds_list_push(my_list, 10);
    ds_list_push(my_list, 1);
    ds_list_push(my_list, 11);
    ds_list_push(my_list, 111);
    ds_list_push(my_list, 1111);
    ds_list_push(my_list, 7);
    for (int i = 0; i < 10; i++) {
       ds_list_push(my_list, rand() % 1000);
    }
    ds_list_print(my_list);
    
    // 2)
    int tail = ds_list_peek(my_list);
    printf("\nCalling ds_list_peek() returns: %d\n", tail);

    // 3)
    tail = ds_list_pop(my_list);
    printf("\nCalling ds_list_pop() returns: %d\n", tail);
    ds_list_print(my_list);

    // 4)
    printf("\nCalling ds_list_remove(7) returns:\n");
    ds_list_remove(my_list, 7);
    ds_list_print(my_list);

    // 5)
    printf("\nCalling ds_heap_new_Heap_from_List() returns:\n");
    Heap* maxPQ2 = ds_heap_new_Heap_from_List(my_list, "max");
    ds_heap_print(maxPQ2);
    #endif

    printf("\n---------------------------------------------------------\n\n");

    #ifdef TEST_VECTOR
    printf("Testing Vector\n");

    // 1)
    Vector* my_vec = ds_vector_new_Vector_from_List(my_list);
    printf("\nCalling ds_vector_new_Vector_from_List() using the following linked list:\n");
    ds_list_print(my_list);
    printf("returns:\n");
    ds_vector_print(my_vec);
    
    // 2)
    int vec = ds_vector_peek(my_vec);
    printf("\nCalling ds_vector_peek() returns: %d\n", vec);
    ds_vector_print(my_vec);

    // 3) 
    vec = ds_vector_pop(my_vec);
    printf("\nCalling ds_vector_pop() returns: %d\n", vec);
    ds_vector_print(my_vec);
    
    // 4)
    vec = 7;
    ds_vector_push(my_vec, vec);
    printf("\nCalling ds_vector_push(7) returns:\n");
    ds_vector_print(my_vec);

    //5
    vec = my_vec->len;
    printf("\nCalling my_vec->len returns: %d\n", vec);
    vec = my_vec->cap;
    printf("Calling my_vec->cap returns: %d\n", vec);
    printf("\nCalling ds_vector_pop() 11 times returns:");
    for (int i = 0; i < 11; i++) {
        vec = ds_vector_pop(my_vec);
        printf(" %d", vec);
    }
    printf("\n");
    ds_vector_print(my_vec);
    vec = my_vec->len;
    printf("\nCalling my_vec->len returns: %d\n", vec);
    vec = my_vec->cap;
    printf("Calling my_vec->cap returns: %d\n", vec);
    vec = ds_vector_pop(my_vec);
    printf("\nCalling ds_vector_pop() returns: %d\n", vec);
    vec = my_vec->len;
    printf("\nCalling my_vec->len returns: %d\n", vec);
    vec = my_vec->cap;
    printf("Calling my_vec->cap returns: %d\n", vec);
    #endif

    printf("\n---------------------------------------------------------\n\n");

    #ifdef TEST_BINARY_TREE
    printf("Testing Binary Tree\n");

    // 1)
    Tree* tree = ds_tree_new_Tree();
    printf("\nCalling ds_tree_add_leaf(...) returns: \n");
    for (int i = 0; i < 10; i++) {
        ds_tree_add_leaf(tree, rand() % 1000);
    }
    ds_tree_print(tree);

    // 2)
    printf("\nRoot is: %d\n", tree->root->key);
    printf("Calling ds_tree_remove() returns: \n");
    ds_tree_remove(tree, tree->root->key);
    ds_tree_print(tree);

    // 3)
    printf("Calling ds_heap_new_Heap_from_Tree() returns: \n");
    Heap* from_tree = ds_heap_new_Heap_from_Tree(tree, "max");
    ds_heap_print(from_tree);
    #endif

    printf("\n---------------------------------------------------------\n\n");

    #ifdef TEST_QUICKSORT
    printf("Testing Binary Tree\n");
    
    // 1)
    printf("\nCreating new Vector: \n");
    Vector* new_vec = ds_vector_new_Vector();
    for (int i = 0; i < 20; i++) {
        ds_vector_push(new_vec, rand() % 1000);
    }
    ds_vector_print(new_vec);
    printf("Sorting Vector: \n");
    ds_quicksort(new_vec);
    ds_vector_print(new_vec);
    printf("Size of new_vec is: %d\n", new_vec->len);
    #endif

    printf("\nDone\n");
    return 0;
}
