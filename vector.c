#include "data_structures.h"

void ds_vector_double_vec_cap(Vector* vec) {
    vec->vec = realloc(vec->vec, (sizeof(int) * vec->cap * 2));
    vec->cap *= 2;
    return;
}

void ds_vector_push(Vector* vec, int x) {
    if (vec == NULL) {
        vec = ds_vector_new_Vector();
    } else if (vec->cap == vec->len) {
        ds_vector_double_vec_cap(vec);
    }
    vec->vec[vec->len] = x;
    vec->len++;
    return;
}

int ds_vector_peek(Vector* vec) {
    int peek = vec->vec[vec->len - 1];
    return peek;
}

void ds_vector_halve_vec_cap(Vector* vec) {
    vec->vec = realloc(vec->vec, (sizeof(int) * vec->cap / 2));
    vec->cap /= 2;
    return;
}

int ds_vector_pop(Vector* vec) {
    int tail = vec->vec[vec->len - 1];
    vec->len--;
    if (vec->len <= (vec->cap / 4)) {
        ds_vector_halve_vec_cap(vec);
    }
    return tail;
}

void ds_vector_print(Vector* vec) {
    printf("[");
    for (int i = 0; i < vec->len - 1; i++) {
        printf("%d, ", vec->vec[i]);
    }
    printf("%d]\n", vec->vec[vec->len - 1]);
    return;
}

void ds_vector_print_partial(Vector* vec) {
    if (vec->len <= 10) {
        ds_vector_print(vec);
        return;
    }
    printf("[");
    for (int i = 0; i < 5; i++) {
        printf("%d, ", vec->vec[i]);
    }
    printf("... , ");
    for (int i = vec->len - 5; i < vec->len - 1; i++) {
        printf("%d, ", vec->vec[i]);
    }
    printf("%d]\n", vec->vec[vec->len - 1]);
    return;
}

Vector* ds_vector_new_Vector() {
    Vector* new_vec = malloc(sizeof(Vector));
    new_vec->vec =  malloc(2 * sizeof(int));
    new_vec->len = 0;
    new_vec->cap = 2;
    return new_vec;
}

int ds_vector_get_content_at_index(Vector* vec, int i) {
    if (i > vec->len) return -1;
    return vec->vec[i];
}

void ds_vector_set_content_at_index_to(Vector* vec, int i, int x) {
    if (i > vec->len) return;
    vec->vec[i] = x;
}

void ds_vector_destroy(Vector* vec) {
    free(vec->vec);
    vec->vec = NULL;
    free(vec);
    vec = NULL;
    return;
}

Vector* ds_vector_new_Vector_from_List(List* list) {
    Vector* new_vec = ds_vector_new_Vector();
    if (list == NULL || list->head == NULL) return new_vec;
    Node* curr = list->head;
    while (curr != NULL) {
        ds_vector_push(new_vec, curr->content);
        curr = curr->next;
    }
    return new_vec;
}
