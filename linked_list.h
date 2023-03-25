#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Linked_List Linked_List;

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