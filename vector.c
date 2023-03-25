#include "vector.h"

void double_vec_cap(Vector* vec) {
    vec->vec = realloc(vec->vec, (sizeof(int) * vec->cap * 2));
    vec->cap *= 2;
    return;
}

void vector_push(Vector* vec, int x) {
    if (vec == NULL) {
        vec = new_Vector();
    } else if (vec->cap == vec->len) {
        double_vec_cap(vec);
    }
    vec->vec[vec->len] = x;
    vec->len++;
    return;
}

int vector_peek(Vector* vec) {
    int peek = vec->vec[vec->len - 1];
    return peek;
}

void halve_vec_cap(Vector* vec) {
    vec->vec = realloc(vec->vec, (sizeof(int) * vec->cap / 2));
    vec->cap /= 2;
    return;
}

int vector_pop(Vector* vec) {
    int tail = vec->vec[vec->len - 1];
    vec->len--;
    if (vec->len <= (vec->cap / 4)) {
        halve_vec_cap(vec);
    }
    return tail;
}

void print_vector(Vector* vec) {
    printf("[");
    for (int i = 0; i < vec->len - 1; i++) {
        printf("%d, ", vec->vec[i]);
    }
    printf("%d]\n", vec->vec[vec->len - 1]);
    return;
}

Vector* new_Vector() {
    Vector* new_vec = malloc(sizeof(Vector));
    new_vec->vec =  malloc(2 * sizeof(int));
    new_vec->len = 0;
    new_vec->cap = 2;
    new_vec->peek = vector_peek;
    new_vec->pop = vector_pop;
    new_vec->push = vector_push;
    new_vec->print = print_vector;
    return new_vec;
}

Vector* from_ll_to_vector(Linked_List* list) {
    Vector* new_vec = new_Vector();
    if (list == NULL || list->head == NULL) return new_vec;
    Node* curr = list->head;
    while (curr != NULL) {
        new_vec->push(new_vec, curr->content);
        curr = curr->next;
    }
    return new_vec;
}
