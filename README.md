# DataStructures_C
A few common data structures implemented in C including Heap (max or min), Linked List and Vectors

main.c constains some unit tests for all included data structures

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

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Vector API:
int     ds_vector_pop(Vector* vec);
int     ds_vector_peek(Vector* vec);
int     ds_vector_get_content_at_index(Vector* vec, int i);
void    ds_vector_print(Vector* vec);
void    ds_vector_push(Vector* vec, int x);
void    ds_vector_remove(Vector* vec, int x);
void    ds_vector_set_content_at_index_to(Vector* vec, int i, int x);
Vector* ds_vector_new_Vector_from_List(List* list);
Vector* ds_vector_new_Vector();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Heap API:
int   ds_heap_pop(Heap* Heap);
int   ds_heap_peek(Heap* Heap);
void  ds_heap_print(Heap* Heap);
void  ds_heap_push(Heap* Heap, int content);
Heap* ds_heap_new_Heap(char* type);
Heap* ds_heap_new_Heap_from_Tree(Tree* tree, char* type);
Heap* ds_heap_new_Heap_from_List(List* list, char* type);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// List API:
int   ds_list_pop(List* list);
int   ds_list_peek(List* list);
void  ds_list_print(List* list);
void  ds_list_push(List* list, int x);
void  ds_list_remove(List* list, int x);
List* ds_list_new_List();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Tree API:
void  ds_tree_print(Tree* tree);
void  ds_tree_remove(Tree* tree, int key);
void  ds_tree_add_leaf(Tree* tree, int x);
Tree* ds_tree_new_Tree();
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// QuickSort API:
void ds_quicksort(Vector* vec);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
```

List of functions and structs intended for internal use only:

```

// Node of a Linked List. Should not be accessible to the user
typedef struct Node {
    int content;
    struct Node* next;
} Node;

// Leaf node of Binary Tree. Should not be accessible to the user
typedef struct Leaf {
    int key;
    int height;
    struct Leaf* left;
    struct Leaf* right;
} Leaf;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Vector internal functions:
void    ds_vector_double_vec_cap(Vector* vec);
void    ds_vector_halve_vec_cap(Vector* vec);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Heap internal functions:
void  ds_heap_swim(Heap** Heap, int index);
void  ds_heap_sink(Heap** Heap, int index);
void ds_heap_new_Heap_from_Tree_recursive(Heap* Heap, Leaf* leaf);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// List internal functions:
Node* ds_list_new_Node(int x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Tree internal functions:
int   ds_tree_balance(Leaf* leaf);
int   ds_tree_max_child_height(Leaf* leaf);
void  ds_tree_print_recursive(Leaf* leaf);
Leaf* ds_tree_new_Leaf(int x);
Leaf* ds_tree_find_min(Leaf* node);
Leaf* ds_tree_left_rotate(Leaf* leaf);
Leaf* ds_tree_right_rotate(Leaf* leaf);
Leaf* ds_tree_remove_recursive(Leaf* leaf, int key);
Leaf* ds_tree_add_leaf_recursive(Leaf* tree, int x);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// QuickSort internal functions:
void ds_quicksort_recursive(int arr[], int left, int right);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
```
