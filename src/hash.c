#include "data_structures.h"
// testing github access 
static int hashtable_hash(char* str, int size) {
    int i = 0;
    for (int j = 0; str[j]; j++) {
        i += str[j];
    }
    return i % size;
}

void hashtable_destroy(HashTable* ht) {
    for (int i = 0; i < ht->cap; i++) {
        if (ht->table[i] != NULL) {
            HashNode* curr = ht->table[i];
            HashNode* next = curr->next;
            free(curr);
            curr = NULL;
            while(next != NULL) {
                curr = next;
                next = curr->next;
                free(curr);
                curr = NULL;
            }
        }
    }
    free(ht->table);
    ht->table = NULL;
    free(ht);
    ht = NULL;   
}

static void hashtable_destroy_table(HashNode** table, int size) {
    for (int i = 0; i < size; i++) {
        if (table[i] != NULL) {
            HashNode* curr = table[i];
            HashNode* next = curr->next;
            free(curr);
            curr = NULL;
            while(next != NULL) {
                curr = next;
                next = curr->next;
                free(curr);
                curr = NULL;
            }
        }
    }
    free(table);
    table = NULL;
}

static void hashtable_halve(HashTable* ht) {
    HashNode** new_table = calloc((unsigned long) ht->cap / 2, sizeof(HashNode*));
    HashNode** old_table = ht->table;
    ht->table = new_table;
    ht->size = 0;
    ht->cap /= 2; 

    for (int i = 0; i < ht->cap * 2; i++) {
        if (old_table[i] != NULL) {
            HashNode* curr = old_table[i];
            hashtable_add(ht, curr->value);
            while(curr->next != NULL) {
                curr = curr->next;
                hashtable_add(ht, curr->value);
            }
        }
    }
    hashtable_destroy_table(old_table, ht->cap * 2);
}


int hashtable_remove(HashTable* ht, char* str) {
    int hash = hashtable_hash(str, ht->cap);
    if (ht->table[hash] != NULL) {
        HashNode* curr = ht->table[hash];
        HashNode* next = curr->next;
        if (strcmp(curr->value, str) == 0) {
            ht->table[hash] = next;
            ht->size--;
            free(curr);
            curr = NULL;
            if(ht->size <= ht->cap / 4 && ht->size >= 1024) {
                hashtable_halve(ht);
            }
            return 1;
        }
        while(curr->next != NULL) {
            if (curr->next->value == str) {
                HashNode* temp = curr->next;
                curr->next = curr->next->next;
                free(temp);
                temp = NULL;
                ht->size--;
                if (ht->size <= ht->cap / 4 && ht->size >= 1024) {
                    hashtable_halve(ht);
                }   
                return 1;
            }
            curr = curr->next;
        }
    }
    return 0;
}


static void double_hashtable(HashTable* ht) {
    HashNode** new_table = calloc((unsigned long) ht->cap * 2, sizeof(HashNode*));
    HashNode** old_table = ht->table;
    ht->table = new_table;
    ht->size = 0;
    ht->cap *= 2; 

    for (int i = 0; i < ht->cap / 2; i++) {
        if (old_table[i] != NULL) {
            HashNode* curr = old_table[i];
            hashtable_add(ht, curr->value);
            while(curr->next != NULL) {
                hashtable_add(ht, curr->value);
                curr = curr->next;
            }
        }
    }
    hashtable_destroy_table(old_table, ht->cap / 2);
}

void hashtable_add(HashTable* ht, char* str) {
    int hash = hashtable_hash(str, ht->cap);
    if (ht->table[hash] == NULL) {
        HashNode* new_hash = malloc(sizeof(HashNode));
        new_hash->value = str;
        new_hash->next = NULL;
        ht->table[hash] = new_hash;
        ht->size++;
        if(ht->size >= ht->cap * 0.75) {
            double_hashtable(ht);
        }
        return;
    } 
    else {
        HashNode* curr = ht->table[hash];
        if (strcmp(curr->value, str) == 0)
                return;
        while(curr->next != NULL) {
            if (strcmp(curr->value, str) == 0)
                return;
            curr = curr->next;
        }
        curr->next = malloc(sizeof(curr));
        curr->next->value = str;
        curr->next->next = NULL;
        ht->size++;
        if(ht->size >= ht->cap * 0.75) {
            double_hashtable(ht);
        }
    }
    return;
}

void hashtable_print(HashTable* ht) {
    printf("#####\n");
    printf("Hashtabe len:%d Hashtable cap: %d\n", ht->size, ht->cap);
    int j = 0;
    for (int i = 0; i < ht->cap; i++) {
        if (ht->table[i] != NULL) {
            HashNode* curr = ht->table[i];
            printf("%d -> (%d: %s)\n", j, i, curr->value);
            j++;
            while(curr->next != NULL) {
                curr = curr->next;
                printf("%d -> (%d: %s)\n", j, i, curr->value);
                j++;
            }
        }
    }
    printf("#####\n");
}

void hashtable_print_partial(HashTable* ht) {
    printf("## \n");
    printf("Hashtable len: %d\n", ht->size);
    printf("Hashtable cap: %d\n", ht->cap);
    int j = 0;
    for (int i = 0; i < ht->cap; i++) {
        if (ht->table[i] != NULL) {
            HashNode* curr = ht->table[i];
            printf("%d -> (%d: %s)\n", j, i, curr->value);
            j++;
            while(curr->next != NULL) {
                curr = curr->next;
                printf("%d -> (%d: %s)\n", j, i, curr->value);
                j++;
            }
        }
    }
    printf("## \n");
    printf("Hashtabe len:%d Hashtable cap: %d\n", ht->size, ht->cap);
}

HashTable* ds_new_hashtable() {
    HashTable* table = malloc(sizeof(HashTable));
    table->size = 0;
    table->cap = 1024;
    table->table = calloc(1024, sizeof(HashNode*));
    return table;
}
