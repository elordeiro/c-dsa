#include "data_structures.h"

static void swim(Heap** Heap, int index) {
    if (index == 1) return;
    int current = vector_get((*Heap)->vec, index);
    int parent = vector_get((*Heap)->vec, index / 2);
    if (strcmp(((*Heap)->type), "max") == 0) {
        if (current > parent) {
            int temp = current;
            vector_set((*Heap)->vec, index, parent);
            vector_set((*Heap)->vec, index / 2, temp);
            swim(Heap, (index / 2));
        }
    } else {
        if (current < parent) {
            int temp = current;
            vector_set((*Heap)->vec, index, parent);
            vector_set((*Heap)->vec, index / 2, temp);
            swim(Heap, (index / 2));
        }
    }
    return;
    
}

static void sink(Heap** Heap, int index) {
    if (index * 2 > (*Heap)->tail) return;
    int parent = vector_get((*Heap)->vec, index);
    int left_child = vector_get((*Heap)->vec, index * 2);
    int right_child = vector_get((*Heap)->vec, index * 2 + 1);
    if (strcmp((*Heap)->type, "max") == 0) {
        if (parent > left_child && parent > right_child) return;
        if (left_child > right_child) {
            int temp = parent;
            vector_set((*Heap)->vec, index, left_child);
            vector_set((*Heap)->vec, index * 2, temp);
            sink(Heap, (index * 2));
        } else {
            int temp = parent;
            vector_set((*Heap)->vec, index, right_child);
            vector_set((*Heap)->vec, index*2 + 1, temp);
            sink(Heap, (index*2 + 1));
        }
    } else {
        if (parent < left_child && parent < right_child) return;
        if (left_child < right_child) {
            int temp = parent;
            vector_set((*Heap)->vec, index, left_child);
            vector_set((*Heap)->vec, index * 2, temp);
            sink(Heap, (index * 2));
        } else {
            int temp = parent;
            vector_set((*Heap)->vec, index, right_child);
            vector_set((*Heap)->vec, index * 2 + 1, temp);
            sink(Heap, (index*2 + 1));
        }
    }
    return;
}

static void new_heap_from_tree_recursive(Heap* Heap, Leaf* leaf) {
    if (leaf == NULL) return;
    heap_push(Heap, leaf->key);
    new_heap_from_tree_recursive(Heap, leaf->left);
    new_heap_from_tree_recursive(Heap, leaf->right);
    return;
}

int heap_peek(Heap* Heap) {
    return vector_get(Heap->vec, Heap->head);
}

void heap_push(Heap* Heap, int content) {
    if (Heap->head < 0) {
        vector_push(Heap->vec, 0);
        Heap->head = 1;
        Heap->tail = 1;
        vector_push(Heap->vec, content);
        return;
    }
    Heap->tail++;
    vector_push(Heap->vec, content);
    swim(&Heap, Heap->tail);
    return;
}


int heap_pop(Heap* Heap) {
    int max_or_min = vector_get(Heap->vec, Heap->head);
    vector_set(Heap->vec, Heap->head, vector_get(Heap->vec, Heap->tail--));
    vector_pop(Heap->vec);
    sink(&Heap, Heap->head);
    return max_or_min;
}

void heap_print_partial(Heap* Heap) {
    if (Heap == NULL) return;
    if (Heap->vec->len <= 10) {
        heap_print(Heap);
        return;
    }
    printf("[");
    for (int i = 1; i < 6; i++) {
        printf("%d, ", vector_get(Heap->vec, i));
    }
    printf("... , ");
    for (int i = Heap->tail - 4; i < Heap->tail; i++) {
        printf("%d, ", vector_get(Heap->vec, i));
    }
    printf("%d]\n", vector_get(Heap->vec, Heap->tail));
    return;
}

void heap_print(Heap* Heap) {
    if (Heap == NULL) return;
    printf("[");
    for (int i = 1; i < Heap->tail; i++) {
        printf("%d, ", vector_get(Heap->vec, i));
    }
    printf("%d]\n", vector_get(Heap->vec, Heap->tail));
    return;
}

Heap* ds_new_heap_from_list(List* list, char* type) {
    Heap* hp = ds_new_heap(type);
    if (list == NULL || list->head == NULL) return hp;
    Node* curr = list->head;
    while (curr != NULL) {
        heap_push(hp, curr->content);
        curr = curr->next;
    }
    return hp;
}


// Heapify a Binary Tree
Heap* ds_new_heap_from_tree(Tree* tree, char* type) {
    Heap* hp = ds_new_heap(type);
    if (tree == NULL || tree->root == NULL) return hp;
    new_heap_from_tree_recursive(hp, tree->root);
    return hp;
}


void heap_destroy(Heap* heap) {
    vector_destroy(heap->vec);
    free(heap);
    heap = NULL;
    return;
}

Heap* ds_new_heap(char* type) {
    Heap* new_Heap = malloc(sizeof(Heap));
    new_Heap->type = type;
    new_Heap->vec = ds_new_vector(1024);
    new_Heap->head = -1;
    new_Heap->tail = -1;
    return new_Heap;
}
