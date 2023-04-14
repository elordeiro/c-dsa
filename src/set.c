#include "data_structures.h"

static kvPair* new_kvpair(int k, char* v) {
    kvPair* new_kv = malloc(sizeof(kvPair));
    new_kv->key = k;
    new_kv->value = v;
    new_kv->height = 1;
    new_kv->left = NULL;
    new_kv->right = NULL;
    return new_kv;
}

static SetTree* new_SetTree() {
    SetTree* new_tree = malloc(sizeof(SetTree));
    new_tree->root = NULL;
    return new_tree;
}

static int max_child_height(kvPair* kvpair) {
    if (kvpair == NULL) return 0;
    int x = 0;
    int y = 0;
    if (kvpair->left != NULL) x = kvpair->left->height;
    if (kvpair->right != NULL) y = kvpair->right->height;
    return (x > y)? x : y;
}

static int get_balance(kvPair* kvpair) {
    if (kvpair == NULL) return 0;
    int x = 0;
    int y = 0;
    if (kvpair->left != NULL) x = kvpair->left->height;
    if (kvpair->right != NULL) y = kvpair->right->height;
    return (x - y);
}

static kvPair* left_rotate(kvPair* x) {
    kvPair* y = x->right;
    kvPair* T2 = NULL; 
    if (y != NULL) T2 = y->left;

    if (y != NULL) y->left = x;
    x->right = T2;
 
    x->height = max_child_height(x) + 1;
    if (y != NULL) y->height = max_child_height(y) + 1;
    
    return y;
}

static kvPair* right_rotate(kvPair* y) {
    kvPair* x = y->left;
    kvPair* T2 = NULL;
    if (x != NULL) T2 = x->right;
 
    if (x != NULL) x->right = y;
    y->left = T2;
    
    y->height = max_child_height(y) + 1;
    if (x != NULL) x->height = max_child_height(x) + 1;
    
    return x;
}

static kvPair* add_recursive(kvPair* kvpair, int k, char* v) {
    if (kvpair == NULL) {
        return new_kvpair(k, v);
    }
    if (k < kvpair->key) kvpair->left = add_recursive(kvpair->left, k, v);
    else if (k > kvpair->key) kvpair->right = add_recursive(kvpair->right, k, v);
    else {
        kvpair->value = v;
        return kvpair;
    }

    kvpair->height = max_child_height(kvpair) + 1;
    
    int balance = get_balance(kvpair);
  
    // Left Left Case
    if (kvpair->left != NULL)
        if (balance > 1 &&  k <  kvpair->left->key)
            return right_rotate(kvpair);
 
    // Right Right Case
    if (kvpair->right != NULL)
        if (balance < -1 && k > kvpair->right->key)
            return left_rotate(kvpair);
 
    // Left Right Case
    if (kvpair->left != NULL) {
        if (balance > 1 && k > kvpair->left->key) {
            kvpair->left = left_rotate(kvpair->left);
            return right_rotate(kvpair);
        }
    }
    // Right Left Case
    if (kvpair->right != NULL) {
        if (balance < -1 && k < kvpair->right->key) {
            kvpair->right = right_rotate(kvpair->right);
            return left_rotate(kvpair);
        }
    }
    return kvpair;
}

static void set_add_bs(Set* set, int k, char* v) {
    if (set->set == NULL) {
        set->set = new_SetTree();
        ((SetTree*)set->set)->root = new_kvpair(k, v);
        return;
    }
    if (((SetTree*)set->set)->root == NULL) {
        kvPair* new_kv = new_kvpair(k, v);
        ((SetTree*)set->set)->root = new_kv;
        return;
    }
    ((SetTree*)set->set)->root = add_recursive(((SetTree*)set->set)->root, k, v);
    return;
}

static void set_add_hash(Set* set, int k, char* v) {
    hashtable_add((HashTable*)set->set, v);
}

void set_add(Set* set, int k, char* v) {
    if (strcmp(set->type, "bs") == 0) {
        set_add_bs(set, k, v);
    } else {
        set_add_hash(set, k, v);
    }
}

static kvPair* find_min(kvPair* node) {
    kvPair* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

static kvPair* remove_recursive(kvPair* kvpair, int key) {
    if (kvpair == NULL) return kvpair;

    if (key < kvpair->key) kvpair->left = remove_recursive(kvpair->left, key);
    else if (key > kvpair->key) kvpair->right = remove_recursive(kvpair->right, key);
    else {
        // Case 1: kvpair node or only one child
        if (kvpair->left == NULL) {
            kvPair* temp = kvpair->right;
            free(kvpair);
            return temp;
        }
        else if (kvpair->right == NULL) {
            kvPair* temp = kvpair->left;
            free(kvpair);
            return temp;
        }
        // Case 2: node has two children
        kvPair* temp = find_min(kvpair->right);
        kvpair->key = temp->key;
        kvpair->value = temp->value;
        kvpair->right = remove_recursive(kvpair->right, temp->key);
    }
    
    kvpair->height = max_child_height(kvpair) + 1;

    int balance = get_balance(kvpair);  
    // Left Left Case
    if (kvpair->left != NULL)
        if (balance > 1 && get_balance(kvpair->left) >= 0)
            return right_rotate(kvpair);
 
    // Left Right Case
    if (kvpair->left != NULL)
        if (balance > 1 && get_balance(kvpair->left) < 0) {
            kvpair->left = left_rotate(kvpair->left);
            return right_rotate(kvpair);
        }
    // Right Right Case
    if (kvpair->right != NULL)
        if (balance < -1 && get_balance(kvpair->right) <= 0)
            return left_rotate(kvpair);
 
    // Right Left Case
    if (kvpair->right != NULL)
        if (balance < -1 && get_balance(kvpair->right) > 0) {
            kvpair->right = right_rotate(kvpair->right);
            return left_rotate(kvpair);
        }
    return kvpair;
}

// Function to delete a node with a given key from the tree
static void set_remove_bs(Set* set, int key) {
    if (set->set == NULL || ((SetTree*)set->set)->root == NULL) {
        return;
    }
    ((SetTree*)set->set)->root = remove_recursive(((SetTree*)set->set)->root, key);
}

static void set_remove_hash(Set* set, int key) {
    
}

void set_remove(Set* set, int key) {
    if (strcmp(set->type, "bs") == 0) {
        set_remove_bs(set, key);
    } else {
        set_remove_hash(set, key);
    }
}

static void print_recursive(kvPair* kvpair) {
    if (kvpair == NULL) return;
    print_recursive(kvpair->left);
    printf(" (%d: %s) ", kvpair->key, kvpair->value);
    print_recursive(kvpair->right);
    return;
}

// *__Print entire Tree__
static void set_print_bs(Set* set) {
    if (set == NULL || set->set == NULL || ((SetTree*)set->set)->root == NULL) return;
    printf("{");
    print_recursive(((SetTree*)set->set)->root);
    printf("}\n");
    return;
}

static void set_print_hash(Set* set) {

}

void set_print(Set* set) {
    if (strcmp(set->type, "bs") == 0) {
        set_print_bs(set);
    } else {
        set_print_hash(set);
    }
}

// **__Internal recursive function__
static void print_partial_recursive(kvPair* kvpair, int* count) {
    if (kvpair == NULL) return;
    print_partial_recursive(kvpair->left, count);
    if (*count < 7) {
        (*count)++;
        printf(" (%d: %s) ", kvpair->key, kvpair->value);
    }
    print_partial_recursive(kvpair->right, count);
    return;
}

// **__Print a partial Tree with a maximun of 7 nodes__
// **__Partial print example: [1, 2, 3, 4, 5, 6, 7, ...]__
static void set_print_partial_bs(Set* set) {
    if (set == NULL || set->set == NULL || ((SetTree*)set->set)->root == NULL) return;
    printf("{");
    int count = 0;
    print_partial_recursive(((SetTree*)set->set)->root, &count);
    printf("...}\n");
    return;
}

static void set_print_partial_hash(Set* set) {

}

void set_print_partial(Set* set) {
    if (strcmp(set->type, "bs") == 0) {
        set_print_partial_bs(set);
    } else {
        set_print_partial_hash(set);
    }
}

static void destroy_recursive(kvPair* kvpair) {
    if (kvpair == NULL) return;
    destroy_recursive(kvpair->left);
    destroy_recursive(kvpair->right);
    free(kvpair);
    kvpair = NULL;
    return;
}

static void set_destroy_bs(Set* set) {
    destroy_recursive(((SetTree*)set->set)->root);
    free(set->set);
    set->set = NULL;
    free(set);
    set = NULL;
    return;
}

static void set_destroy_hash(Set* set) {
    
}

void set_destroy(Set* set) {
    if (strcmp(set->type, "bs") == 0) {
        set_destroy_bs(set);
    } else {
        set_destroy_hash(set);
    }
}

Set* ds_new_set(char* type) {
    Set* new_set = malloc(sizeof(Set));
    new_set->type = type;
    new_set->set = NULL;
    return new_set;
}
