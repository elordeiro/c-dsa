#pragma once
#include <time.h>
#include <_types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Resizeble array: 
// Doubles in size when at full capicity and halves its size when capicity is 1 / 4 full
typedef struct Vector {
    int* vec;
    int len;
    int cap;
} Vector;

// Max or Min heap should be specified at creation time via the "type" parameter
typedef struct Heap {
    char* type;
    Vector* vec;
    int head;
    int tail;
    int cap;
} Heap;

// Node of a Linked List. Should not be accessible to the user
typedef struct Node {
    int content;
    struct Node* next;
} Node;

// Singly linked list. Can act as a stack supporting push and pop functions
typedef struct List {
    struct Node* head;
    struct Node* tail;
} List;

// Leaf node of Binary Tree. Should not be accessible to the user
typedef struct Leaf {
    int key;
    int height;
    struct Leaf* left;
    struct Leaf* right;
} Leaf;

// (AVL) Binary Tree. Balance factor of 1. 
typedef struct Tree {
    Leaf* root;
} Tree;

// Key Value Pair. Should not be accessible to the user
typedef struct kvPair {
    int key;
    char* value;
    int height;
    struct kvPair* left;
    struct kvPair* right;
} kvPair;

// (AVL) Binary Tree. Root node is kvPair instead of Leaf Balance factor of 1.
typedef struct SetTree {
    kvPair* root;
} SetTree;

// Set of unique elements. Implemented as a Binary Tree with different Leaf Node
typedef struct Set {
    SetTree* tree;
} Set;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Vector functions that should be external:
int     ds_vector_pop(Vector* vec);
int     ds_vector_peek(Vector* vec);
int     ds_vector_get_content_at_index(Vector* vec, int i);
void    ds_vector_print(Vector* vec);
void    ds_vector_destroy(Vector* vec);
void    ds_vector_push(Vector* vec, int x);
void    ds_vector_print_partial(Vector* vec);
void    ds_vector_remove(Vector* vec, int x);
void    ds_vector_set_content_at_index_to(Vector* vec, int i, int x);
Vector* ds_vector_new_Vector_from_List(List* list);
Vector* ds_vector_new_Vector();

// Vector functions that should be internal:
void    ds_vector_double_vec_cap(Vector* vec);
void    ds_vector_halve_vec_cap(Vector* vec);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Heap functions that should be external:
int   ds_heap_pop(Heap* Heap);
int   ds_heap_peek(Heap* Heap);
void  ds_heap_print(Heap* Heap);
void  ds_heap_destroy(Heap* heap);
void  ds_heap_print_partial(Heap* Heap);
void  ds_heap_push(Heap* Heap, int content);
Heap* ds_heap_new_Heap(char* type);
Heap* ds_heap_new_Heap_from_Tree(Tree* tree, char* type);
Heap* ds_heap_new_Heap_from_List(List* list, char* type);

// Heap functions that should be internal:
void ds_heap_swim(Heap** Heap, int index);
void ds_heap_sink(Heap** Heap, int index);
void ds_heap_new_Heap_from_Tree_recursive(Heap* Heap, Leaf* leaf);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// List functions that should be external:
int   ds_list_pop(List* list);
int   ds_list_peek(List* list);
void  ds_list_print(List* list);
void  ds_list_destroy(List* list);
void  ds_list_push(List* list, int x);
void  ds_list_remove(List* list, int x);
void  ds_list_print_partial(List* list);
List* ds_list_new_List();
List* ds_list_new_List_from_Vector(Vector* vec);

// List functions that should be internal:
Node* ds_list_new_Node(int x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// All tree functions that should be external:
void  ds_tree_print(Tree* tree);
void  ds_tree_print_partial(Tree* tree);
void  ds_tree_remove(Tree* tree, int key);
void  ds_tree_add_leaf(Tree* tree, int x);
void  ds_tree_destroy(Tree* tree);
Tree* ds_tree_new_Tree();

// All tree functions that should be internal:
int   ds_tree_balance(Leaf* leaf);
int   ds_tree_max_child_height(Leaf* leaf);
void  ds_tree_print_recursive(Leaf* leaf);
void  ds_tree_destroy_recursive(Leaf* leaf);
void  ds_tree_print_partial_recursive(Leaf* leaf, int* count);
Leaf* ds_tree_new_Leaf(int x);
Leaf* ds_tree_find_min(Leaf* node);
Leaf* ds_tree_left_rotate(Leaf* leaf);
Leaf* ds_tree_right_rotate(Leaf* leaf);
Leaf* ds_tree_remove_recursive(Leaf* leaf, int key);
Leaf* ds_tree_add_leaf_recursive(Leaf* tree, int x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Sorting algorithms external functions:
void ds_sort_mergesort_list(List** list);
void ds_sort_mergesort_vector(Vector* vec);
void ds_sort_quicksort_list(List** list);
void ds_sort_quicksort_vector(Vector* vec);
void ds_sort_bubblesort_vector(Vector* vec);
void ds_sort_bubblesort_list(List* list);

// Sorting algorithms internal functions:
int* ds_sort_mergesort(int* arr, int length);
void ds_sort_quicksort(int arr[], int left, int right);
int* ds_sort_merge(int* left_arr, int left_arr_len, int* right_arr, int right_arr_len);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Set functions that should be external:
Set*     ds_set_new_Set();
void     ds_set_add_kvpair(Set* set, int k, char* v);
void     ds_set_print(Set* set);
void     ds_set_print_partial(Set* set) ;
void     ds_set_remove(Set* set, int key);
void     ds_set_destroy(Set* set);

// Set functions that should be internal:
int      ds_set_balance(kvPair* kvpair);
int      ds_set_max_child_height(kvPair* kvpair);
void     ds_set_print_recursive(kvPair* kvpair);
void     ds_set_print_partial_recursive(kvPair* kvpair, int* count);
void     ds_set_destroy_recursive(kvPair* kvpair);
kvPair*  ds_set_add_kvpair_recursive(kvPair* kvpair, int k, char* v);
kvPair*  ds_set_left_rotate(kvPair* x);
kvPair*  ds_set_right_rotate(kvPair* y);
kvPair*  ds_set_find_min(kvPair* node);
kvPair*  ds_set_remove_recursive(kvPair* kvpair, int key) ;
kvPair*  ds_set_new_kvpair(int k, char* v);
SetTree* ds_set_new_SetTree();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
