#include <time.h>
#include "heap.h"
#include "vector.h"
#include "linked_list.h"

#define TEST_Heap 1
#define TEST_LINKED_LIST 1
#define TEST_VECTOR 1

int main () {
    srand(time(NULL));
    
    #ifdef TEST_Heap
    printf("Testing Max Heap\n");
    // 1)
    printf("\nCalling maxPQ->push(...) returns:\n");
    Heap* maxPQ = new_Heap("max");
    for (int i = 0; i < 10; i++) {
        maxPQ->push(maxPQ, rand() % 1000);
    }
    maxPQ->print(maxPQ, maxPQ->head);
    
    // 2)
    int max = maxPQ->peek(maxPQ);
    printf("\nCalling maxPQ->peek() returns: %d\n", max);
    
    // 3)
    max = maxPQ->pop(maxPQ);
    printf("\nCalling maxPQ->pop() returns: %d\n", max);
    maxPQ->print(maxPQ, maxPQ->head);
    
    printf("\n----------------------------------------------------------------------------------------\n\n");
    
    printf("Testing Min Heap\n");
    
    // 1)
    printf("\nCalling minPQ->push(...) returns:\n");
    Heap* minPQ = new_Heap("min");
    for (int i = 0; i < 10; i++) {
        minPQ->push(minPQ, rand() % 1000);
    }
    minPQ->print(minPQ, minPQ->head);
    
    // 2)
    int min = minPQ->peek(minPQ);
    printf("\nCalling minPQ->peek() returns: %d\n", min);
    
    // 3)
    min = minPQ->pop(minPQ);
    printf("\nCalling minPQ->pop() returns: %d\n", min);
    minPQ->print(minPQ, minPQ->head);

    #endif

    printf("\n----------------------------------------------------------------------------------------\n\n");
    
    #if TEST_LINKED_LIST
    printf("Testing Linked List\n");
    
    // 1)
    printf("\nCalling my_list->push(...) returns:\n");
    Linked_List* my_list = new_list();
    my_list->push(my_list, 1000);
    my_list->push(my_list, 100);
    my_list->push(my_list, 10);
    my_list->push(my_list, 1);
    my_list->push(my_list, 11);
    my_list->push(my_list, 111);
    my_list->push(my_list, 1111);
    my_list->push(my_list, 7);
    for (int i = 0; i < 10; i++) {
       my_list->push(my_list, rand() % 1000);
    }
    my_list->print(my_list);
    
    // 2)
    int tail = my_list->peek(my_list);
    printf("\nCalling my_list->peek() returns: %d\n", tail);

    // 3)
    tail = my_list->pop(my_list);
    printf("\nCalling my_list->pop() returns: %d\n", tail);
    my_list->print(my_list);

    // 4)
    printf("\nCalling my_list->remove(7) returns:\n");
    my_list->remove(my_list, 7);
    my_list->print(my_list);

    // 5)
    printf("\nCalling my_list->heapify() returns:\n");
    Heap* maxPQ2 = heapify_from_linked_list(my_list, "max");
    maxPQ2->print(maxPQ2, maxPQ2->head);
    #endif

    printf("\n----------------------------------------------------------------------------------------\n\n");

    #ifdef TEST_VECTOR
    printf("Testing Vector\n");

    // 1)
    Vector* my_vec = from_ll_to_vector(my_list);
    printf("\nCalling from_ll_to_vector() using the following linked list:\n");
    my_list->print(my_list);
    printf("returns:\n");
    my_vec->print(my_vec);
    
    // 2)
    int vec = my_vec->peek(my_vec);
    printf("\nCalling my_vec->peek() returns: %d\n", vec);
    my_vec->print(my_vec);

    // 3) 
    vec = my_vec->pop(my_vec);
    printf("\nCalling my_vec->pop() returns: %d\n", vec);
    my_vec->print(my_vec);
    
    // 4)
    vec = 7;
    my_vec->push(my_vec, vec);
    printf("\nCalling my_vec->push(7) returns:\n");
    my_vec->print(my_vec);
    #endif

    printf("\nDone\n");
    return 0;
}