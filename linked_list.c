#include "data_structures.h"

Node* ds_list_new_Node(int x) {
    Node* nd = malloc(sizeof(Node));
    nd->content = x;
    nd->next = NULL;
    return nd;
}

int ds_list_pop(List* list) {
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

void ds_list_push(List* list, int x) {
    if (list->head == NULL) {
        Node* new_nd = ds_list_new_Node(x);
        list->head = new_nd;
        list->tail = new_nd;
        return;
    }
    Node* curr = list->head;
    while (curr->next != NULL) {
        curr = curr->next; 
    }
    curr->next = ds_list_new_Node(x);
    list->tail = curr->next;
    return;
}

int ds_list_peek(List* list) {
    if (list == NULL || list->head == NULL) return -1;
    return list->tail->content;
}

void ds_list_remove(List* list, int x) {
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

void ds_list_print(List* list) {
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

List* ds_list_new_List() {
    List* ll = malloc(sizeof(List));
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
}
