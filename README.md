# DataStructures_C
A few common data structures and algorithms implemented in C  
Data Structures:
- Binary Tree  
- Heap  
- Linked List  
- Set  
- Vector  
- 
Algorithms:
- Merge Sort  
- Quick Sort  
- Bubble Sort  

main.c contains some unit tests for all included data structures  

List of functions and structs supported for external use:  


```
// Resizeble array: 
// Doubles in size when at full capacity and halves its size when capacity is 1 / 4 full
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

// Singly linked list. Can act as a stack supporting push and pop functions
typedef struct List {
    struct Node* head;
    struct Node* tail;
} List;

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
```

Test Results:

```
Testing Vector

Calling ds_vector_push(...) returns:
[618, 611, 821, 988, 852, 782, 810, 215, 227, 457, 417, 300, 949, 556, 741, 222]

Calling ds_vector_peek() returns: 222

Calling ds_vector_pop() returns: 222
[618, 611, 821, 988, 852, 782, 810, 215, 227, 457, 417, 300, 949, 556, 741]

Calling ds_vector_get_content_at_index(7) returns: 215

ds_vector_set_content_at_index(7, 77) returns: 
[618, 611, 821, 988, 852, 782, 810, 77, 227, 457, 417, 300, 949, 556, 741]

Calling ds_vector_remove(77) returns: 
[618, 611, 821, 988, 852, 782, 810, 227, 457, 417, 300, 949, 556, 741]

Calling ds_vector_new_Vector_from_List() using following list returns: 
[578, 63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]
[578, 63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]

vec->len: 14 vec->cap: 16
Calling ds_vector_pop() 9 times returns:  741  556  949  300  417  457  227  810  782 
[618, 611, 821, 988, 852]

vec->len: 5 vec->cap: 16
Calling ds_vector_pop() returns: 852
vec->len: 4 vec->cap: 8
[618, 611, 821, 988]

---------------------------------------------------------

Testing Max Heap

Calling ds_heap_push(...) returns:
[988, 875, 949, 852, 821, 810, 782, 611, 529, 578, 417, 300, 618, 556, 741, 215, 222, 227, 63, 457]
[988, 875, 949, 852, 821, ... , 215, 222, 227, 63, 457]

Calling ds_heap_peek() returns: 988

Calling ds_heap_pop() returns: 988
[949, 875, 810, 852, 821, 618, 782, 611, 529, 578, 417, 300, 457, 556, 741, 215, 222, 227, 63]

---------------------------------------------------------

Testing Min Heap

Calling ds_heap_push(...) returns:
[63, 215, 300, 222, 417, 782, 556, 611, 227, 578, 457, 821, 949, 810, 741, 988, 875, 618, 529, 852]
[63, 215, 300, 222, 417, ... , 988, 875, 618, 529, 852]

Calling ds_heap_peek() returns: 63

Calling ds_heap_pop() returns: 63
[215, 222, 300, 227, 417, 782, 556, 611, 529, 578, 457, 821, 949, 810, 741, 988, 875, 618, 852]

---------------------------------------------------------

Testing ds_heap_new_Heap_from_List()

Calling ds_heap_new_Heap_from_List() using following list returns:
[578, 63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]
[988, 949, 810, 875, 618, 529, 782, 852, 821, 457, 417, 227, 215, 556, 741, 63, 578, 300, 611, 222]
Testing ds_heap_new_Heap_from_Tree()

Calling ds_heap_new_Heap_from_Tree() using following tree returns:
[ 63  215  222  227  300  417  457  529  556  578  611  618  741  782  810  821  852  875  949  988 ]
[988, 949, 782, 852, 875, 578, 741, 611, 821, 556, 529, 222, 300, 227, 618, 215, 457, 417, 810, 63]
Testing Linked List

Calling ds_list_push(...) returns:
[578, 63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]

Calling ds_list_peek() returns: 578

Calling ds_list_pop() returns: 578
[63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]

-- Add 145 -- Calling ds_list_remove(145) returns:
[145, 63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]
[63, 529, 875, 222, 741, 556, 949, 300, 417, 457, 227, 215, 810, 782, 852, 988, 821, 611, 618]

Calling ds_list_new_list_from_Vector() using the following vector returns:
[828, 809, 832, 273, 444, 524, 106, 399, 660, 433, 793, 329, 658, 914, 473, 516, 920, 673, 283, 130]
[828, 809, 832, 273, 444, 524, 106, 399, 660, 433, 793, 329, 658, 914, 473, 516, 920, 673, 283, 130]

---------------------------------------------------------

Testing Binary Tree

Calling ds_tree_add_leaf(...) returns: 
[ 145  187  242  287  339  346  351  377  462  486  491  536  545  568  571  632  647  742  841  890 ]
[ 145  187  242  287  339  346  351 ...]

Root is: 491
Calling ds_tree_remove() returns: 
[ 145  187  242  287  339  346  351  377  462  486  536  545  568  571  632  647  742  841  890 ]
[ 145  187  242  287  339  346  351 ...]

---------------------------------------------------------

Testing Set

Calling ds_set_add_kvpair(...) returns: 
{ 
  (0: c++)  (1: c)  (2: python)  (3: ruby)  (4: java)  (5: javascript)  (6: c#)  (7: go)  (8: rust)  
  (9: haskell)  (10: scala)   (11: erlang)  (12: prolog)  (13: lisp)  (14: clojure)  (15: ocaml)  (16: f#)  
  (17: swift)  (18: kotlin)  (19: dart)  (20: php)  (21: perl)  (22: bash)  (23: zsh)  (24: fish)
  (25: powershell)  (26: c-shell)  (27: korn-shell)  (28: elisp)  (29: scheme)  (30: racket)  (31: lua)  (32: julia)  
  (33: fortran)  (34: cobol)  (35: pascal)  (36: ada)  (37: basic)  (38: visual-basic)  (39: delphi)  (40: matlab)
  (41: octave)  (42: r)  (43: s)  (44: tcl)  (45: awk)  (46: sed)  (47: groovy)  (48: haxe)  
  (49: nim)  (50: nimrod)  (51: nemerle)  (52: boo)  (53: fantom)  (54: factor)  (55: io)  (56: ioke)
  (57: j)  (58: jade)  (59: j) 
}
{ (0: c++)  (1: c)  (2: python)  (3: ruby)  (4: java)  (5: javascript)  (6: c#) ...}

Calling ds_set_add_kvpair(4, my_lang) returns: 
{ (0: c++)  (1: c)  (2: python)  (3: ruby)  (4: my_lang)  (5: javascript)  (6: c#) ...}

Calling ds_set_remove(3) returns: 
{ (0: c++)  (1: c)  (2: python)  (4: ruby)  (5: javascript)  (6: c#)  (7: go) ...}

---------------------------------------------------------


Benchmarking sorting algorithms

Sorting Vectors

Sorting vec1 with mergesort. Vec1 len: 1000
[618, 988, 810, 457, 949, ... , 737, 903, 669, 453, 915]
[2, 2, 3, 4, 4, ... , 993, 996, 997, 999, 999]
Mergesort took 0.000308s

Sorting vec2 with quicksort. Vec2 len: 1000
[611, 852, 215, 417, 556, ... , 160, 845, 120, 476, 252]
[1, 1, 1, 1, 1, ... , 996, 996, 997, 999, 999]
Quicksort took  0.000061s

Sorting vec3 with bubblesort. Vec3 len: 1000
[821, 782, 227, 300, 741, ... , 96, 604, 974, 445, 530]
[0, 1, 1, 2, 3, ... , 994, 994, 994, 999, 999]
Bubblesort took  0.001952s

Sorting Lists

Sorting ll1 with mergesort.
[915, 453, 669, 903, 737, 423, 928, ...]
[2, 2, 3, 4, 4, 5, 6, ...]
Mergesort took  0.000389s

Sorting ll2 with quicksort.
[252, 476, 120, 845, 160, 517, 197, ...]
[1, 1, 1, 1, 1, 1, 3, ...]
Quicksort took  0.000142s

Sorting ll3 with bubblesort.
[530, 445, 974, 604, 96, 428, 212, ...]
[0, 1, 1, 2, 3, 6, 8, ...]
Bubblesort took  0.002100s

Sorting Exponetially larger vectors

Vector size: 1024
Mergesort Time: 0.000429  Quicksort Time: 0.000059
Quicksort was faster than Mergesort by: 0.000370s
----------------------------------------------------

Vector size: 2048
Mergesort Time: 0.000729  Quicksort Time: 0.000126
Quicksort was faster than Mergesort by: 0.000603s
----------------------------------------------------

Vector size: 4096
Mergesort Time: 0.001436  Quicksort Time: 0.000303
Quicksort was faster than Mergesort by: 0.001133s
----------------------------------------------------

Vector size: 8192
Mergesort Time: 0.003122  Quicksort Time: 0.000650
Quicksort was faster than Mergesort by: 0.002472s
----------------------------------------------------

Vector size: 16384
Mergesort Time: 0.005593  Quicksort Time: 0.001283
Quicksort was faster than Mergesort by: 0.004310s
----------------------------------------------------

Vector size: 32768
Mergesort Time: 0.012176  Quicksort Time: 0.002873
Quicksort was faster than Mergesort by: 0.009303s
----------------------------------------------------

Vector size: 65536
Mergesort Time: 0.022869  Quicksort Time: 0.007717
Quicksort was faster than Mergesort by: 0.015152s
----------------------------------------------------

Vector size: 131072
Mergesort Time: 0.048141  Quicksort Time: 0.021894
Quicksort was faster than Mergesort by: 0.026247s
----------------------------------------------------

Vector size: 262144
Mergesort Time: 0.090553  Quicksort Time: 0.066608
Quicksort was faster than Mergesort by: 0.023945s
----------------------------------------------------

Vector size: 524288
Mergesort Time: 0.182901  Quicksort Time: 0.237874
Mergesort was faster than Quicksort by: 0.054973s
----------------------------------------------------

Vector size: 1048576
Mergesort Time: 0.377793  Quicksort Time: 0.869564
Mergesort was faster than Quicksort by: 0.491771s
----------------------------------------------------

Vector size: 2097152
Mergesort Time: 0.747816  Quicksort Time: 3.321189
Mergesort was faster than Quicksort by: 2.573373s
----------------------------------------------------

Vector size: 4194304
Mergesort Time: 1.521898  Quicksort Time: 12.946567
Mergesort was faster than Quicksort by: 11.424669s
----------------------------------------------------

Vector size: 8388608
Mergesort Time: 3.127553  Quicksort Time: 50.425276
Mergesort was faster than Quicksort by: 47.297723s
----------------------------------------------------


Done
```
