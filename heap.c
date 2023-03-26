#include "data_structures.h"

void ds_heap_swim(Heap** Heap, int index) {
    if (index == 1) return;
    int current = ds_vector_get_content_at_index((*Heap)->vec, index);
    int parent = ds_vector_get_content_at_index((*Heap)->vec, index / 2);
    if (strcmp(((*Heap)->type), "max") == 0) {
        if (current > parent) {
            int temp = current;
            ds_vector_set_content_at_index_to((*Heap)->vec, index, parent);
            ds_vector_set_content_at_index_to((*Heap)->vec, index / 2, temp);
            ds_heap_swim(Heap, (index / 2));
        }
    } else {
        if (current < parent) {
            int temp = current;
            ds_vector_set_content_at_index_to((*Heap)->vec, index, parent);
            ds_vector_set_content_at_index_to((*Heap)->vec, index / 2, temp);
            ds_heap_swim(Heap, (index / 2));
        }
    }
    return;
    
}

void ds_heap_sink(Heap** Heap, int index) {
    if (index * 2 > (*Heap)->tail) return;
    int parent = ds_vector_get_content_at_index((*Heap)->vec, index);
    int left_child = ds_vector_get_content_at_index((*Heap)->vec, index * 2);
    int right_child = ds_vector_get_content_at_index((*Heap)->vec, index * 2 + 1);
    if (strcmp((*Heap)->type, "max") == 0) {
        if (parent > left_child && parent > right_child) return;
        if (left_child > right_child) {
            int temp = parent;
            ds_vector_set_content_at_index_to((*Heap)->vec, index, left_child);
            ds_vector_set_content_at_index_to((*Heap)->vec, index * 2, temp);
            ds_heap_sink(Heap, (index * 2));
        } else {
            int temp = parent;
            ds_vector_set_content_at_index_to((*Heap)->vec, index, right_child);
            ds_vector_set_content_at_index_to((*Heap)->vec, index*2 + 1, temp);
            ds_heap_sink(Heap, (index*2 + 1));
        }
    } else {
        if (parent < left_child && parent < right_child) return;
        if (left_child < right_child) {
            int temp = parent;
            ds_vector_set_content_at_index_to((*Heap)->vec, index, left_child);
            ds_vector_set_content_at_index_to((*Heap)->vec, index * 2, temp);
            ds_heap_sink(Heap, (index * 2));
        } else {
            int temp = parent;
            ds_vector_set_content_at_index_to((*Heap)->vec, index, right_child);
            ds_vector_set_content_at_index_to((*Heap)->vec, index * 2 + 1, temp);
            ds_heap_sink(Heap, (index*2 + 1));
        }
    }
    return;
}

int ds_heap_peek(Heap* Heap) {
    return ds_vector_get_content_at_index(Heap->vec, Heap->head);
}

void ds_heap_push(Heap* Heap, int content) {
    if (Heap->head < 0) {
        ds_vector_push(Heap->vec, 0);
        Heap->head = 1;
        Heap->tail = 1;
        ds_vector_push(Heap->vec, content);
        return;
    }
    Heap->tail++;
    ds_vector_push(Heap->vec, content);
    ds_heap_swim(&Heap, Heap->tail);
    return;
}


int ds_heap_pop(Heap* Heap) {
    int max_or_min = ds_vector_get_content_at_index(Heap->vec, Heap->head);
    ds_vector_set_content_at_index_to(Heap->vec, Heap->head, ds_vector_get_content_at_index(Heap->vec, Heap->tail--));
    ds_vector_pop(Heap->vec);
    ds_heap_sink(&Heap, Heap->head);
    return max_or_min;
}

void ds_heap_print(Heap* Heap) {
    if (Heap == NULL) return;
    printf("[");
    for (int i = 1; i < Heap->tail; i++) {
        printf("%d, ", ds_vector_get_content_at_index(Heap->vec, i));
    }
    printf("%d]\n", ds_vector_get_content_at_index(Heap->vec, Heap->tail));
    return;
}

Heap* ds_heap_new_Heap_from_List(List* list, char* type) {
    Heap* hp = ds_heap_new_Heap(type);
    if (list == NULL || list->head == NULL) return hp;
    Node* curr = list->head;
    while (curr != NULL) {
        ds_heap_push(hp, curr->content);
        curr = curr->next;
    }
    return hp;
}

void ds_heap_new_Heap_from_Tree_recursive(Heap* Heap, Leaf* leaf) {
    if (leaf == NULL) return;
    ds_heap_push(Heap, leaf->key);
    ds_heap_new_Heap_from_Tree_recursive(Heap, leaf->left);
    ds_heap_new_Heap_from_Tree_recursive(Heap, leaf->right);
    return;
}

// Heapify a Binary Tree
Heap* ds_heap_new_Heap_from_Tree(Tree* tree, char* type) {
    Heap* hp = ds_heap_new_Heap(type);
    if (tree == NULL || tree->root == NULL) return hp;
    ds_heap_new_Heap_from_Tree_recursive(hp, tree->root);
    return hp;
}

void ds_heap_destroy(Heap* heap) {
    ds_vector_destroy(heap->vec);
    free(heap);
    heap = NULL;
    return;
}

Heap* ds_heap_new_Heap(char* type) {
    Heap* new_Heap = malloc(sizeof(Heap));
    new_Heap->type = type;
    new_Heap->vec = ds_vector_new_Vector();
    new_Heap->head = -1;
    new_Heap->tail = -1;
    return new_Heap;
}
