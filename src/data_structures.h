#pragma once
#include <time.h>
#include <_types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Resizeble array: 
// Doubles in size when at full capicity and halves its size when capicity is 1 / 4 full
typedef struct vector {
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
    char* type;
    void* set;
} Set;

//
typedef struct HashNode {
    char* value;
    struct HashNode* next;
} HashNode;

//
typedef struct HashTable {
    int size;
    int cap;
    HashNode** table;
} HashTable;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Vector API:
void    vector_push(Vector* vec, int x);
int     vector_peek(Vector* vec);
int     vector_pop(Vector* vec);
void    vector_remove(Vector* vec, int x);
int     vector_get(Vector* vec, int i);
void    vector_set(Vector* vec, int i, int x);
void    vector_print(Vector* vec);
void    vector_print_partial(Vector* vec);
void    vector_destroy(Vector* vec);
Vector* ds_new_vector(int size);
Vector* ds_new_vector_from_list(List* list);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Heap API:
void  heap_push(Heap* Heap, int content);
int   heap_peek(Heap* Heap);
int   heap_pop(Heap* Heap);
void  heap_print(Heap* Heap);
void  heap_print_partial(Heap* Heap);
void  heap_destroy(Heap* heap);
Heap* ds_new_heap(char* type);
Heap* ds_new_heap_from_list(List* list, char* type);
Heap* ds_new_heap_from_tree(Tree* tree, char* type);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// List API:
void  list_push(List* list, int x);
int   list_peek(List* list);
int   list_pop(List* list);
void  list_remove(List* list, int x);
void  list_print(List* list);
void  list_print_partial(List* list);
void  list_destroy(List* list);
List* ds_new_list();
List* ds_new_list_from_vec(Vector* vec);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// todo virtual function newlist from vec 
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Tree API:
void  tree_add(Tree* tree, int x);
void  tree_remove(Tree* tree, int key);
void  tree_print(Tree* tree);
void  tree_print_partial(Tree* tree);
void  tree_destroy(Tree* tree);
Tree* ds_new_tree();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Set API:
void set_add(Set* set, int k, char* v);
void set_print(Set* set);
void set_print_partial(Set* set) ;
void set_remove(Set* set, int key);
void set_destroy(Set* set);
Set* ds_new_set();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Hashtable API:
void hashtable_add(HashTable* tb, char* str);
int hashtable_remove(HashTable* ht, char* str);
void hashtable_print(HashTable* tb);
void hashtable_print_partial(HashTable* ht);
void hashtable_destroy(HashTable* ht);
HashTable* ds_new_hashtable();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Sorting algorithms API:
void sort_list_mergesort(List** list);
void sort_list_quicksort(List** list);
void sort_list_bubblesort(List* list);
void sort_vector_mergesort(Vector* vec);
void sort_vector_quicksort(Vector* vec);
void sort_vector_bubblesort(Vector* vec);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
