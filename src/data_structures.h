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

// Node of a Linked List.
typedef struct Node {
    int content;
    struct Node* next;
} Node;

// Singly linked list. Can act as a stack supporting push and pop functions
typedef struct List {
    struct Node* head;
    struct Node* tail;
} List;

// Leaf node of Binary Tree.
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

// Key Value Pair.
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

// Set of unique elements. Implemented as a Binary Tree with kvPair as leaf node.
typedef struct Set {
    SetTree* tree;
} Set;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Vector API:
void    ds_vector_push(Vector* vec, int x);
int     ds_vector_peek(Vector* vec);
int     ds_vector_pop(Vector* vec);
void    ds_vector_remove(Vector* vec, int x);
int     ds_vector_get_content_at_index(Vector* vec, int i);
void    ds_vector_set_content_at_index_to(Vector* vec, int i, int x);
void    ds_vector_print(Vector* vec);
void    ds_vector_print_partial(Vector* vec);
void    ds_vector_destroy(Vector* vec);
Vector* ds_vector_new_Vector();
Vector* ds_vector_new_Vector_from_List(List* list);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Heap API:
void  ds_heap_push(Heap* Heap, int content);
int   ds_heap_peek(Heap* Heap);
int   ds_heap_pop(Heap* Heap);
void  ds_heap_print(Heap* Heap);
void  ds_heap_print_partial(Heap* Heap);
void  ds_heap_destroy(Heap* heap);
Heap* ds_heap_new_Heap(char* type);
Heap* ds_heap_new_Heap_from_List(List* list, char* type);
Heap* ds_heap_new_Heap_from_Tree(Tree* tree, char* type);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// List API:
void  ds_list_push(List* list, int x);
int   ds_list_peek(List* list);
int   ds_list_pop(List* list);
void  ds_list_remove(List* list, int x);
void  ds_list_print(List* list);
void  ds_list_print_partial(List* list);
void  ds_list_destroy(List* list);
List* ds_list_new_List();
List* ds_list_new_List_from_Vector(Vector* vec);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Tree API:
void  ds_tree_add_leaf(Tree* tree, int x);
void  ds_tree_remove(Tree* tree, int key);
void  ds_tree_print(Tree* tree);
void  ds_tree_print_partial(Tree* tree);
void  ds_tree_destroy(Tree* tree);
Tree* ds_tree_new_Tree();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Set API:
void ds_set_add_kvpair(Set* set, int k, char* v);
void ds_set_print(Set* set);
void ds_set_print_partial(Set* set) ;
void ds_set_remove(Set* set, int key);
void ds_set_destroy(Set* set);
Set* ds_set_new_Set();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Sorting algorithms API:
void ds_sort_mergesort_list(List** list);
void ds_sort_mergesort_vector(Vector* vec);
void ds_sort_quicksort_list(List** list);
void ds_sort_quicksort_vector(Vector* vec);
void ds_sort_bubblesort_vector(Vector* vec);
void ds_sort_bubblesort_list(List* list);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
