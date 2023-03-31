#include "data_structures.h"

// **__This is a helper function and should not be called externally__
static kvPair* ds_set_new_kvpair(int k, char* v) {
    kvPair* new_kv = malloc(sizeof(kvPair));
    new_kv->key = k;
    new_kv->value = v;
    new_kv->height = 1;
    new_kv->left = NULL;
    new_kv->right = NULL;
    return new_kv;
}

static SetTree* ds_set_new_SetTree() {
    SetTree* new_tree = malloc(sizeof(SetTree));
    new_tree->root = NULL;
    return new_tree;
}

static int ds_set_max_child_height(kvPair* kvpair) {
    if (kvpair == NULL) return 0;
    int x = 0;
    int y = 0;
    if (kvpair->left != NULL) x = kvpair->left->height;
    if (kvpair->right != NULL) y = kvpair->right->height;
    return (x > y)? x : y;
}

static int ds_set_balance(kvPair* kvpair) {
    if (kvpair == NULL) return 0;
    int x = 0;
    int y = 0;
    if (kvpair->left != NULL) x = kvpair->left->height;
    if (kvpair->right != NULL) y = kvpair->right->height;
    return (x - y);
}

static kvPair* ds_set_left_rotate(kvPair* x) {
    kvPair* y = x->right;
    kvPair* T2 = NULL; 
    if (y != NULL) T2 = y->left;

    if (y != NULL) y->left = x;
    x->right = T2;
 
    x->height = ds_set_max_child_height(x) + 1;
    if (y != NULL) y->height = ds_set_max_child_height(y) + 1;
    
    return y;
}

static kvPair* ds_set_right_rotate(kvPair* y) {
    kvPair* x = y->left;
    kvPair* T2 = NULL;
    if (x != NULL) T2 = x->right;
 
    if (x != NULL) x->right = y;
    y->left = T2;
    
    y->height = ds_set_max_child_height(y) + 1;
    if (x != NULL) x->height = ds_set_max_child_height(x) + 1;
    
    return x;
}

static kvPair* ds_set_add_kvpair_recursive(kvPair* kvpair, int k, char* v) {
    if (kvpair == NULL) {
        return ds_set_new_kvpair(k, v);
    }
    if (k < kvpair->key) kvpair->left = ds_set_add_kvpair_recursive(kvpair->left, k, v);
    else if (k > kvpair->key) kvpair->right = ds_set_add_kvpair_recursive(kvpair->right, k, v);
    else {
        kvpair->value = v;
        return kvpair;
    }

    kvpair->height = ds_set_max_child_height(kvpair) + 1;
    
    int balance = ds_set_balance(kvpair);
  
    // Left Left Case
    if (kvpair->left != NULL)
        if (balance > 1 &&  k <  kvpair->left->key)
            return ds_set_right_rotate(kvpair);
 
    // Right Right Case
    if (kvpair->right != NULL)
        if (balance < -1 && k > kvpair->right->key)
            return ds_set_left_rotate(kvpair);
 
    // Left Right Case
    if (kvpair->left != NULL) {
        if (balance > 1 && k > kvpair->left->key) {
            kvpair->left = ds_set_left_rotate(kvpair->left);
            return ds_set_right_rotate(kvpair);
        }
    }
    // Right Left Case
    if (kvpair->right != NULL) {
        if (balance < -1 && k < kvpair->right->key) {
            kvpair->right = ds_set_right_rotate(kvpair->right);
            return ds_set_left_rotate(kvpair);
        }
    }
    return kvpair;
}

void ds_set_add_kvpair(Set* set, int k, char* v) {
    if (set->tree == NULL) {
        set->tree = ds_set_new_SetTree();
        set->tree->root = ds_set_new_kvpair(k, v);
        return;
    }
    if (set->tree->root == NULL) {
        kvPair* new_kv = ds_set_new_kvpair(k, v);
        set->tree->root = new_kv;
        return;
    }
    set->tree->root = ds_set_add_kvpair_recursive(set->tree->root, k, v);
    return;
}

static kvPair* ds_set_find_min(kvPair* node) {
    kvPair* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

static kvPair* ds_set_remove_recursive(kvPair* kvpair, int key) {
    if (kvpair == NULL) return kvpair;

    if (key < kvpair->key) kvpair->left = ds_set_remove_recursive(kvpair->left, key);
    else if (key > kvpair->key) kvpair->right = ds_set_remove_recursive(kvpair->right, key);
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
        kvPair* temp = ds_set_find_min(kvpair->right);
        kvpair->key = temp->key;
        kvpair->right = ds_set_remove_recursive(kvpair->right, temp->key);
    }
    
    kvpair->height = ds_set_max_child_height(kvpair) + 1;

    int balance = ds_set_balance(kvpair);  
    // Left Left Case
    if (kvpair->left != NULL)
        if (balance > 1 && ds_set_balance(kvpair->left) >= 0)
            return ds_set_right_rotate(kvpair);
 
    // Left Right Case
    if (kvpair->left != NULL)
        if (balance > 1 && ds_set_balance(kvpair->left) < 0) {
            kvpair->left = ds_set_left_rotate(kvpair->left);
            return ds_set_right_rotate(kvpair);
        }
    // Right Right Case
    if (kvpair->right != NULL)
        if (balance < -1 && ds_set_balance(kvpair->right) <= 0)
            return ds_set_left_rotate(kvpair);
 
    // Right Left Case
    if (kvpair->right != NULL)
        if (balance < -1 && ds_set_balance(kvpair->right) > 0) {
            kvpair->right = ds_set_right_rotate(kvpair->right);
            return ds_set_left_rotate(kvpair);
        }
    return kvpair;
}

// Function to delete a node with a given key from the tree
void ds_set_remove(Set* set, int key) {
    if (set->tree == NULL || set->tree->root == NULL) {
        return;
    }
    set->tree->root = ds_set_remove_recursive(set->tree->root, key);
}

static void ds_set_print_recursive(kvPair* kvpair) {
    if (kvpair == NULL) return;
    ds_set_print_recursive(kvpair->left);
    printf(" (%d: %s) ", kvpair->key, kvpair->value);
    ds_set_print_recursive(kvpair->right);
    return;
}

// *__Print entire Tree__
void ds_set_print(Set* set) {
    if (set == NULL || set->tree == NULL || set->tree->root == NULL) return;
    printf("{");
    ds_set_print_recursive(set->tree->root);
    printf("}\n");
    return;
}

// **__Internal recursive function__
static void ds_set_print_partial_recursive(kvPair* kvpair, int* count) {
    if (kvpair == NULL) return;
    ds_set_print_partial_recursive(kvpair->left, count);
    if (*count < 7) {
        (*count)++;
        printf(" (%d: %s) ", kvpair->key, kvpair->value);
    }
    ds_set_print_partial_recursive(kvpair->right, count);
    return;
}

// **__Print a partial Tree with a maximun of 7 nodes__
// **__Partial print example: [1, 2, 3, 4, 5, 6, 7, ...]__
void ds_set_print_partial(Set* set) {
    if (set == NULL || set->tree == NULL || set->tree->root == NULL) return;
    printf("{");
    int count = 0;
    ds_set_print_partial_recursive(set->tree->root, &count);
    printf("...}\n");
    return;
}

static void ds_set_destroy_recursive(kvPair* kvpair) {
    if (kvpair == NULL) return;
    ds_set_destroy_recursive(kvpair->left);
    ds_set_destroy_recursive(kvpair->right);
    free(kvpair);
    kvpair = NULL;
    return;
}

void ds_set_destroy(Set* set) {
    ds_set_destroy_recursive(set->tree->root);
    free(set->tree);
    set->tree = NULL;
    free(set);
    set = NULL;
    return;
}

Set* ds_set_new_Set() {
    Set* new_set = malloc(sizeof(Set));
    new_set->tree = ds_set_new_SetTree();
    return new_set;
}
