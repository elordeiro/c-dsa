#include "data_structures.h"

static Node* new_node(int x) {
    Node* nd = malloc(sizeof(Node));
    nd->content = x;
    nd->next = NULL;
    return nd;
}

int list_pop(List* list) {
    if (list == NULL || list->head == NULL) return -1;
    int poped = list->head->content;
    if (list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        return poped;
    }

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    temp = NULL;
    return poped;
}

void list_push(List* list, int x) {
    if (list->head == NULL) {
        Node* new_nd = new_node(x);
        list->head = new_nd;
        list->tail = new_nd;
        return;
    }
    Node* temp = list->head;
    list->head = new_node(x);
    list->head->next = temp;
    return;
}

int list_peek(List* list) {
    if (list == NULL || list->head == NULL) return -1;
    return list->head->content;
}

void list_remove(List* list, int x) {
    if (list == NULL || list->head == NULL) return;
    if (list->head->content == x) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        temp = NULL;
        return;
    }
    Node* curr = list->head;
    while (curr != NULL) {
        if (curr->next->content == x) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            temp = NULL;
            return;
        }
        curr = curr->next;
    }
    return;
}

void list_print(List* list) {
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

void list_print_partial(List* list) {
    int count = 0;
    if (list == NULL || list->head == NULL) return;
    Node* curr = list->head;
    printf("[");
    while (curr->next != NULL) {
        if (count >= 7) {
            break;
        }
        count++;
        printf("%d, ", curr->content);
        curr = curr->next;
    }
    printf("...]\n");
    return;
}

void list_destroy(List* list) {
    if (list == NULL) return;
    Node* current = list->head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = NULL;
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
    list = NULL;
    return;
}

static void push_reverse(List* list, int x) {
    if (list->head == NULL) {
        Node* new_nd = new_node(x);
        list->head = new_nd;
        list->tail = new_nd;
        return;
    }
    Node* temp = new_node(x);
    list->tail->next = temp;
    list->tail = temp;
    return;
}

List* ds_new_list_from_vec(Vector* vec) {
    List* ll = ds_new_list();
    for (int i = 0; i < vec->len; i++) {
        push_reverse(ll, vec->vec[i]);
    }
    return ll;
}
List* ds_new_list() {
    List* ll = malloc(sizeof(List));
    ll->head = NULL;
    ll->tail = NULL;
    return ll;
}
