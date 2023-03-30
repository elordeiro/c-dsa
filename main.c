
#include "data_structures.h"
double execution_time;
clock_t start, end;

void test_heap() {
    srand((u_int32_t) time(NULL));        
    printf("Testing Max Heap\n");
    // 1)
    printf("\nCalling ds_heap_push(...) returns:\n");
    Heap* maxPQ = ds_heap_new_Heap("max");
    for (int i = 0; i < 20; i++) {
        ds_heap_push(maxPQ, rand() % 1000);
    }
    ds_heap_print(maxPQ);
    ds_heap_print_partial(maxPQ);
    
    // 2)
    int max = ds_heap_peek(maxPQ);
    printf("\nCalling ds_heap_peek() returns: %d\n", max);
    
    // 3)
    max = ds_heap_pop(maxPQ);
    printf("\nCalling ds_heap_pop() returns: %d\n", max);
    ds_heap_print(maxPQ);

    ds_heap_destroy(maxPQ);
    
    printf("\n---------------------------------------------------------\n\n");
    
    printf("Testing Min Heap\n");
    
    // 1)
    printf("\nCalling ds_heap_push(...) returns:\n");
    Heap* minPQ = ds_heap_new_Heap("min");
    for (int i = 0; i < 20; i++) {
        ds_heap_push(minPQ, rand() % 1000);
    }
    ds_heap_print(minPQ);
    ds_heap_print_partial(minPQ);
    
    // 2)
    int min = ds_heap_peek(minPQ);
    printf("\nCalling ds_heap_peek() returns: %d\n", min);
    
    // 3)
    min = ds_heap_pop(minPQ);
    printf("\nCalling ds_heap_pop() returns: %d\n", min);
    ds_heap_print(minPQ);

    ds_heap_destroy(minPQ);
    printf("\n---------------------------------------------------------\n\n");
}

void test_linked_list() {
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
    
    // 6)
    printf("\nCalling ds_lis_new_list_from_Vector() using the following vector returns:\n");
    Vector* vec = ds_vector_new_Vector();
    for (int i = 0; i < 20; i++) {
        ds_vector_push(vec, rand() % 1000);
    }
    ds_vector_print(vec);
    List* new_list = ds_list_new_List_from_Vector(vec);
    ds_list_print(new_list);

    ds_vector_destroy(vec);
    ds_heap_destroy(maxPQ2);
    ds_list_destroy(my_list);
    ds_list_destroy(new_list);
    printf("\n---------------------------------------------------------\n\n");
}

void test_vector() {
    printf("Testing Vector\n");

    // 1)
    List* my_list = ds_list_new_List();
    for (int i = 0; i < 16; i++) {
        ds_list_push(my_list, rand() % 1000);
    }
    Vector* my_vec = ds_vector_new_Vector_from_List(my_list);
    printf("\nCalling ds_vector_new_Vector_from_List() using the following linked list:\n");
    ds_list_print(my_list);
    printf("returns:\n");
    ds_vector_print(my_vec);
    ds_list_destroy(my_list);
    
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

    // 5)
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
    vec = ds_vector_peek(my_vec);
    ds_vector_remove(my_vec, vec);
    printf("\nCalling ds_vector_remove(%d) returns: %d\n", vec, vec);
    vec = my_vec->len;
    printf("\nCalling my_vec->len returns: %d\n", vec);
    vec = my_vec->cap;
    printf("Calling my_vec->cap returns: %d\n", vec);
    ds_vector_print(my_vec);

    ds_vector_destroy(my_vec);
    printf("\n---------------------------------------------------------\n\n");
}

void test_binary_tree() {
    printf("Testing Binary Tree\n");

    // 1)
    Tree* tree = ds_tree_new_Tree();
    printf("\nCalling ds_tree_add_leaf(...) returns: \n");
    for (int i = 0; i < 20; i++) {
        ds_tree_add_leaf(tree, rand() % 1000);
    }
    ds_tree_print(tree);
    ds_tree_print_partial(tree);
    
    // 2)
    printf("\nRoot is: %d\n", tree->root->key);
    printf("Calling ds_tree_remove() returns: \n");
    ds_tree_remove(tree, tree->root->key);
    ds_tree_print(tree);
    ds_tree_print_partial(tree);

    // 3)
    printf("Calling ds_heap_new_Heap_from_Tree() returns: \n");
    Heap* from_tree = ds_heap_new_Heap_from_Tree(tree, "max");
    ds_heap_print(from_tree);

    ds_heap_destroy(from_tree);
    ds_tree_destroy(tree);
    printf("\n---------------------------------------------------------\n\n");
}
void test_sort() {
    srand((u_int32_t) time(NULL)); 
    printf("\nBenchmarking sorting algorithms\n");
    

    //1) 
    printf("\nSorting Vectors\n");
    Vector* vec1 = ds_vector_new_Vector();
    Vector* vec2 = ds_vector_new_Vector();
    Vector* vec3 = ds_vector_new_Vector();

    for (int i = 0; i < 100; i++) {
        ds_vector_push(vec1, rand() % 1000);
        ds_vector_push(vec2, rand() % 1000);
        ds_vector_push(vec3, rand() % 1000);
    }

    printf("\nSorting vec1 with bubblesort. Vec1 len: %d\n", vec1->len);
    ds_vector_print_partial(vec1);
    start = clock();
    ds_sort_bubblesort_vector(vec1);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_vector_print_partial(vec1);
    printf("Bubblesort took %lfs\n", execution_time);
    
    printf("\nSorting vec2 with quicksort. Vec2 len: %d\n", vec2->len);
    ds_vector_print_partial(vec2);
    start = clock();
    ds_sort_quicksort_vector(vec2);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_vector_print_partial(vec2);
    printf("Quicksort took  %lfs\n", execution_time);

    printf("\nSorting vec3 with mergesort. Vec3 len: %d\n", vec2->len);
    ds_vector_print_partial(vec3);
    start = clock();
    ds_sort_mergesort_vector(vec3);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_vector_print_partial(vec3);
    printf("Mergesort took  %lfs\n", execution_time);
    
    ds_vector_destroy(vec1);
    ds_vector_destroy(vec2);
    ds_vector_destroy(vec3);
    
    // 2)
    printf("\nSorting Lists\n");
    List* ll1 = ds_list_new_List();
    List* ll2 = ds_list_new_List();
    List* ll3 = ds_list_new_List();
    
    srand((u_int32_t) time(NULL));
    for (int i = 0; i < 100; i++) {
        ds_list_push(ll1, rand() % 1000);
        ds_list_push(ll2, rand() % 1000);
        ds_list_push(ll3, rand() % 1000);
    }

    printf("\nSorting ll1 with bubblesort.\n");
    ds_list_print_partial(ll1);
    start = clock();
    ds_sort_bubblesort_list(ll1);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_list_print_partial(ll1);
    printf("Bubblesort took  %lfs\n", execution_time);

    printf("\nSorting ll2 with quicksort.\n");
    ds_list_print_partial(ll2);
    start = clock();
    ds_sort_quicksort_list(&ll2);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_list_print_partial(ll2);
    printf("Quicksort took  %lfs\n", execution_time);

    printf("\nSorting ll3 with mergesort.\n");
    ds_list_print_partial(ll3);
    start = clock();
    ds_sort_mergesort_list(&ll3);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    ds_list_print_partial(ll3);
    printf("Mergesort took  %lfs\n", execution_time);

    ds_list_destroy(ll1);
    ds_list_destroy(ll2);
    ds_list_destroy(ll3);
    printf("\n---------------------------------------------------------\n\n");
}

void test_set() {
    // 1)
    // test array with 50 elements 
    char* test[] = {"c++", "c", "python", "ruby", "java", "javascript", "c#", "go", "rust", "haskell", "scala", "erlang", "prolog", "lisp", "clojure", "ocaml", "f#", "swift", "kotlin", "dart", "php", "perl", "bash", "zsh", "fish", "powershell", "c-shell", "korn-shell", "elisp", "scheme", "racket", "lua", "julia", "fortran", "cobol", "pascal", "ada", "basic", "visual-basic", "delphi", "matlab", "octave", "r", "s", "tcl", "awk", "sed", "groovy", "haxe", "nim", "nimrod", "nemerle", "boo", "fantom", "factor", "io", "ioke", "j", "jade", "j"};

    // for (int i = 0; i < 100; i++) {
    //     printf("%s %d, ", test[i], i);
    //     fflush(stdout);
    // }
    printf("Testing Set\n");
    Set* set = ds_set_new_Set();
    printf("\nCalling ds_set_add() returns: \n");
    for (int i = 0; i < 60; i++) {
        ds_set_add_kvpair(set, i, test[i]);
    }
    ds_set_print_partial(set);
    printf("\nCalling ds_set_remove() returns: \n");
    ds_set_remove(set, 3);
    ds_set_print_partial(set);
    ds_set_destroy(set);
    printf("\n---------------------------------------------------------\n\n");
}

int main () {
    // test_heap();
    // test_linked_list();
    test_vector(); 
    // test_binary_tree();
    // test_sort();
    // test_set();
    printf("\nDone\n");
    return 0;
}
