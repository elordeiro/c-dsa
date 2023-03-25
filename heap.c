#include "heap.h"

void swim(Heap** Heap, int index) {
    if (index == 1) return;
    int current = (*Heap)->vec->vec[index];
    int parent = (*Heap)->vec->vec[index / 2];
    if (strcmp(((*Heap)->type), "max") == 0) {
        if (current > parent) {
            int temp = current;
            (*Heap)->vec->vec[index] = parent;
            (*Heap)->vec->vec[index / 2] = temp;
            swim(Heap, (index / 2));
        }
    } else {
        if (current < parent) {
            int temp = current;
            (*Heap)->vec->vec[index] = parent;
            (*Heap)->vec->vec[index / 2] = temp;
            swim(Heap, (index / 2));
        }
    }
    return;
    
}

void sink(Heap** Heap, int index) {
    if (index * 2 > (*Heap)->tail) return;
    int parent = (*Heap)->vec->vec[index];
    int left_child = (*Heap)->vec->vec[index * 2];
    int right_child = (*Heap)->vec->vec[index * 2 + 1];
    if (strcmp((*Heap)->type, "max") == 0) {
        if (parent > left_child && parent > right_child) return;
        if (left_child > right_child) {
            int temp = parent;
            (*Heap)->vec->vec[index] = left_child;
            (*Heap)->vec->vec[index * 2] = temp;
            sink(Heap, (index * 2));
        } else {
            int temp = parent;
            (*Heap)->vec->vec[index] = right_child;
            (*Heap)->vec->vec[index*2 + 1] = temp;
            sink(Heap, (index*2 + 1));
        }
    } else {
        if (parent < left_child && parent < right_child) return;
        if (left_child < right_child) {
            int temp = parent;
            (*Heap)->vec->vec[index] = left_child;
            (*Heap)->vec->vec[index * 2] = temp;
            sink(Heap, (index * 2));
        } else {
            int temp = parent;
            (*Heap)->vec->vec[index] = right_child;
            (*Heap)->vec->vec[index*2 + 1] = temp;
            sink(Heap, (index*2 + 1));
        }
    }
    return;
}

int heap_peek(Heap* Heap) {
    return Heap->vec->vec[Heap->head];
}

void heap_push(Heap* Heap, int content) {
    if (Heap->head < 0) {
        Heap->vec->push(self, 0);
        Heap->head = 1;
        Heap->tail = 1;
        Heap->vec->push(self, content);
        return;
    }
    Heap->tail++;
    Heap->vec->push(self, content);
    swim(&Heap, Heap->tail);
    return;
}


int heap_pop(Heap* Heap) {
    int max_or_min = Heap->vec->vec[Heap->head];
    Heap->vec->vec[Heap->head] = Heap->vec->vec[Heap->tail--];
    Heap->vec->pop(Heap->vec);
    sink(&Heap, Heap->head);
    return max_or_min;
}

void print_queue(Heap* Heap, int index) {
    if (index > Heap->tail) return;
    if (index == Heap->head) { printf("[%d, ", Heap->vec->vec[index]); }
    else if (index == Heap->tail) { printf("%d]\n", Heap->vec->vec[index]); }
    else { printf("%d, ", Heap->vec->vec[index]); }
    print_queue(Heap, ++index);
    return;
}


Heap* new_Heap(char* type) {
    Heap* new_Heap = malloc(sizeof(Heap));
    new_Heap->type = type;
    new_Heap->vec = new_Vector();
    new_Heap->head = -1;
    new_Heap->tail = -1;
    new_Heap->Heap_capicity = 2;
    new_Heap->push = heap_push;
    new_Heap->print = print_queue;
    new_Heap->peek = heap_peek;
    new_Heap->pop = heap_pop;
    new_Heap->Heapify = heapify_from_linked_list;
    return new_Heap; 
}

Heap* heapify_from_linked_list(Linked_List* list, char* type) {
    Heap* hp = new_Heap(type);
    if (list == NULL || list->head == NULL) return hp;
    Node* curr = list->head;
    while (curr != NULL) {
        hp->push(hp, curr->content);
        curr = curr->next;
    }
    return hp;
}