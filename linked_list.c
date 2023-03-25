#include "linked_list.h"

Node* new_node(int x) {
    Node* nd = malloc(sizeof(Node));
    nd->content = x;
    nd->next = NULL;
    return nd;
}

int ll_pop(Linked_List* list) {
    if (list == NULL || list->head == NULL) return -1;
    int poped = list->tail->content;
    if (list->head == list->tail) {
        list->head = NULL;
        free(list->head);
        return poped;
    }

    Node* curr = list->head;
    while (curr->next->next != NULL) {
        curr = curr->next; 
    }
    curr->next = NULL;
    free(curr->next);
    list->tail = curr;
    return poped;
}

void ll_push(Linked_List* list, int x) {
    if (list->head == NULL) {
        Node* new_nd = new_node(x);
        list->head = new_nd;
        list->tail = new_nd;
        return;
    }
    Node* curr = list->head;
    while (curr->next != NULL) {
        curr = curr->next; 
    }
    curr->next = new_node(x);
    list->tail = curr->next;
    return;
}

int ll_peek(Linked_List* list) {
    if (list == NULL || list->head == NULL) return -1;
    return list->tail->content;
}

void ll_remove(Linked_List* list, int x) {
    if (list == NULL || list->head == NULL) return;
    if (list->head->content == x) {
        Node* temp = list->head;
        list->head = list->head->next;
        temp = NULL;
        free(temp);
        return;
    }
    Node* curr = list->head;
    while (curr != NULL) {
        if (curr->next->content == x) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp = NULL;
            free(temp);
            return;
        }
        curr = curr->next;
    }
    return;
}

void print_list(Linked_List* list) {
    if (list == NULL || list->head == NULL) return;
    Node* curr = list->head;
    printf("[");
    while (curr->next != NULL) {
        printf("%d, ", curr->content);
        curr = curr->next;
    }
    printf("%d]\n", curr->content);
    return;
}

Linked_List* new_list() {
    Linked_List* ll = malloc(sizeof(Linked_List));
    ll->head = NULL;
    ll->tail = NULL;
    ll->pop = ll_pop;
    ll->push = ll_push;
    ll->peek = ll_peek;
    ll->remove = ll_remove;
    ll->print = print_list;
    return ll;
}