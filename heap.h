#pragma once
#include <string.h>
#include "vector.h"
#include "linked_list.h"

#define self Heap->vec

typedef struct Heap Heap;

Vector* new_Vector();

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
