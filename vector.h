#pragma once
#include <stdlib.h>
#include "linked_list.h"

typedef struct Vector Vector;

struct Vector {
    int* vec;
    int len;
    int cap;

    int (*pop)(Vector* vec);
    int (*peek)(Vector* vec);
    void (*push)(Vector* vec, int x);
    void (*remove)(Vector* vec, int x);
    void (*print)(Vector* vec);
    Vector* (*from_ll_to_vector)(Linked_List* list);
};

Vector* new_Vector();
int vector_pop(Vector* vec);
int vector_peek(Vector* vec);
void vector_push(Vector* vec, int x);
void vector_remove(Vector* vec, int x);
void print_vector(Vector* vec);
void halve_vec_cap(Vector* vec);
void double_vec_cap(Vector* vec);
Vector* from_ll_to_vector(Linked_List* list);