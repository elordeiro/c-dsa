#pragma once
#include <time.h>
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

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Vector functions that should be external:
int     ds_vector_pop(Vector* vec);
int     ds_vector_peek(Vector* vec);
int     ds_vector_get_content_at_index(Vector* vec, int i);
void    ds_vector_print(Vector* vec);
void    ds_vector_destroy(Vector* vec);
void    ds_vector_push(Vector* vec, int x);
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
void  ds_heap_push(Heap* Heap, int content);
Heap* ds_heap_new_Heap(char* type);
Heap* ds_heap_new_Heap_from_Tree(Tree* tree, char* type);
Heap* ds_heap_new_Heap_from_List(List* list, char* type);

// Heap functions that should be internal:
void  ds_heap_swim(Heap** Heap, int index);
void  ds_heap_sink(Heap** Heap, int index);
void ds_heap_new_Heap_from_Tree_recursive(Heap* Heap, Leaf* leaf);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// List functions that should be internal:
int   ds_list_pop(List* list);
int   ds_list_peek(List* list);
void  ds_list_print(List* list);
void  ds_list_destroy(List* list);
void  ds_list_push(List* list, int x);
void  ds_list_remove(List* list, int x);
List* ds_list_new_List();

// List functions that should be external:
Node* ds_list_new_Node(int x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// All tree functions that should be external:
void  ds_tree_print(Tree* tree);
void  ds_tree_remove(Tree* tree, int key);
void  ds_tree_add_leaf(Tree* tree, int x);
void  ds_tree_destroy(Tree* tree);
Tree* ds_tree_new_Tree();

// All tree functions that should be external:
int   ds_tree_balance(Leaf* leaf);
int   ds_tree_max_child_height(Leaf* leaf);
void  ds_tree_print_recursive(Leaf* leaf);
void  ds_tree_destroy_recursive(Leaf* leaf);
Leaf* ds_tree_new_Leaf(int x);
Leaf* ds_tree_find_min(Leaf* node);
Leaf* ds_tree_left_rotate(Leaf* leaf);
Leaf* ds_tree_right_rotate(Leaf* leaf);
Leaf* ds_tree_remove_recursive(Leaf* leaf, int key);
Leaf* ds_tree_add_leaf_recursive(Leaf* tree, int x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// QuickSort algorithm
void ds_quicksort(Vector* vec);
void ds_quicksort_recursive(int arr[], int left, int right);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>