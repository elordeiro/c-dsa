# DataStructures_C
A few common data structures implemented in C including Heap (max or min), Linked List and Vectors

List of functions and structs in each file  

```
//Vector.h
struct Vector {
    int* vec;
    int len;
    int cap;

    int (*pop)(Vector* vec);
    int (*peek)(Vector* vec);
    void (*push)(Vector* vec, int x);
    void (*remove)(Vector* vec, int x);
    void (*print)(Vector* vec);
    Vector* (*from_ll_to_vector)(Linked_List* list);
};

Vector* new_Vector();
int vector_pop(Vector* vec);
int vector_peek(Vector* vec);
void vector_push(Vector* vec, int x);
void vector_remove(Vector* vec, int x);
void print_vector(Vector* vec);
void halve_vec_cap(Vector* vec);
void double_vec_cap(Vector* vec);
Vector* from_ll_to_vector(Linked_List* list);
```

```
//linked_list.h
struct Node {
    int content;
    struct Node* next;
};

struct Linked_List {
    struct Node* head;
    struct Node* tail;
    int (*pop)(Linked_List* list);
    void (*push)(Linked_List* list, int x);
    int (*peek)(Linked_List* list);
    void (*remove)(Linked_List* list, int x);
    void (*print)(Linked_List* list);
};

int ll_pop(Linked_List* list);
void ll_push(Linked_List* list, int x);
int ll_peek(Linked_List* list);
void ll_remove(Linked_List* list, int x);
void print_list(Linked_List* list);
Node* new_node(int x);
Linked_List* new_list();
```

```
//heap.h
struct Heap {
    char* type;
    Vector* vec;
    int head;
    int tail;
    int Heap_capicity;

    void (*push)(Heap* Heap, int content);
    void (*print)(Heap* Heap, int index);
    int (*peek)(Heap* Heap);
    int (*pop)(Heap* Heap);
    Heap* (*Heapify)(Linked_List* list, char* type);
};

void swim(Heap** Heap, int index);
void sink(Heap** Heap, int index);
void heap_push(Heap* Heap, int content);
int heap_peek(Heap* Heap);
int heap_pop(Heap* Heap);
void print_queue(Heap* Heap, int index);
Heap* heapify_from_linked_list(Linked_List* list, char* type);
Heap* new_Heap(char* type);

```
