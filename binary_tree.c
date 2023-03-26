#include "data_structures.h"

Leaf* ds_tree_new_Leaf(int x) {
    Leaf* new_leaf = malloc(sizeof(Leaf));
    new_leaf->key = x;
    new_leaf->height = 1;
    new_leaf->left = NULL;
    new_leaf->right = NULL;
    return new_leaf;
}

int ds_tree_max_child_height(Leaf* leaf) {
    if (leaf == NULL) return 0;
    int x = 0;
    int y = 0;
    if (leaf->left != NULL) x = leaf->left->height;
    if (leaf->right != NULL) y = leaf->right->height;
    return (x > y)? x : y;
}

int ds_tree_balance(Leaf* leaf) {
    if (leaf == NULL) return 0;
    int x = 0;
    int y = 0;
    if (leaf->left != NULL) x = leaf->left->height;
    if (leaf->right != NULL) y = leaf->right->height;
    return (x - y);
}

Leaf* ds_tree_left_rotate(Leaf* x) {
    Leaf* y = x->right;
    Leaf* T2 = NULL; 
    if (y != NULL) T2 = y->left;

    if (y != NULL) y->left = x;
    x->right = T2;
 
    x->height = ds_tree_max_child_height(x) + 1;
    if (y != NULL) y->height = ds_tree_max_child_height(y) + 1;
    
    return y;
}

Leaf* ds_tree_right_rotate(Leaf* y) {
    Leaf* x = y->left;
    Leaf* T2 = NULL;
    if (x != NULL) T2 = x->right;
 
    if (x != NULL) x->right = y;
    y->left = T2;
    
    y->height = ds_tree_max_child_height(y) + 1;
    if (x != NULL) x->height = ds_tree_max_child_height(x) + 1;
    
    return x;
}

Leaf* ds_tree_add_leaf_recursive(Leaf* leaf, int x){
    if (leaf == NULL) {
        return ds_tree_new_Leaf(x);
    }
    if (x < leaf->key) leaf->left = ds_tree_add_leaf_recursive(leaf->left, x);
    else if (x > leaf->key) leaf->right = ds_tree_add_leaf_recursive(leaf->right, x);
    else return leaf;

    leaf->height = ds_tree_max_child_height(leaf) + 1;
    
    int balance = ds_tree_balance(leaf);
  
    // Left Left Case
    if (leaf->left != NULL)
        if (balance > 1 &&  x <  leaf->left->key)
            return ds_tree_right_rotate(leaf);
 
    // Right Right Case
    if (leaf->right != NULL)
        if (balance < -1 && x > leaf->right->key)
            return ds_tree_left_rotate(leaf);
 
    // Left Right Case
    if (leaf->left != NULL) {
        if (balance > 1 && x > leaf->left->key) {
            leaf->left = ds_tree_left_rotate(leaf->left);
            return ds_tree_right_rotate(leaf);
        }
    }
    // Right Left Case
    if (leaf->right != NULL) {
        if (balance < -1 && x < leaf->right->key) {
            leaf->right = ds_tree_right_rotate(leaf->right);
            return ds_tree_left_rotate(leaf);
        }
    }
    return leaf;
}

void ds_tree_add_leaf(Tree* tree, int x) {
    if (tree == NULL) {
        tree = ds_tree_new_Tree();
        tree->root = ds_tree_new_Leaf(x);
        return;
    }
    if (tree->root == NULL) {
        Leaf* new_leaf = ds_tree_new_Leaf(x);
        tree->root = new_leaf;
        return;
    }
    tree->root = ds_tree_add_leaf_recursive(tree->root, x);
    return;
}

Leaf* ds_tree_find_min(Leaf* node) {
    Leaf* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Leaf* ds_tree_remove_recursive(Leaf* leaf, int key) {
    if (leaf == NULL) return leaf;

    if (key < leaf->key) leaf->left = ds_tree_remove_recursive(leaf->left, key);
    else if (key > leaf->key) leaf->right = ds_tree_remove_recursive(leaf->right, key);
    else {
        // Case 1: leaf node or only one child
        if (leaf->left == NULL) {
            Leaf* temp = leaf->right;
            free(leaf);
            return temp;
        }
        else if (leaf->right == NULL) {
            Leaf* temp = leaf->left;
            free(leaf);
            return temp;
        }
        // Case 2: node has two children
        Leaf* temp = ds_tree_find_min(leaf->right);
        leaf->key = temp->key;
        leaf->right = ds_tree_remove_recursive(leaf->right, temp->key);
    }
    
    leaf->height = ds_tree_max_child_height(leaf) + 1;

    int balance = ds_tree_balance(leaf);  
    // Left Left Case
    if (leaf->left != NULL)
        if (balance > 1 && ds_tree_balance(leaf->left) >= 0)
            return ds_tree_right_rotate(leaf);
 
    // Left Right Case
    if (leaf->left != NULL)
        if (balance > 1 && ds_tree_balance(leaf->left) < 0) {
            leaf->left = ds_tree_left_rotate(leaf->left);
            return ds_tree_right_rotate(leaf);
        }
    // Right Right Case
    if (leaf->right != NULL)
        if (balance < -1 && ds_tree_balance(leaf->right) <= 0)
            return ds_tree_left_rotate(leaf);
 
    // Right Left Case
    if (leaf->right != NULL)
        if (balance < -1 && ds_tree_balance(leaf->right) > 0) {
            leaf->right = ds_tree_right_rotate(leaf->right);
            return ds_tree_left_rotate(leaf);
        }
    return leaf;
}

// Function to delete a node with a given key from the tree
void ds_tree_remove(Tree* tree, int key) {
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    tree->root = ds_tree_remove_recursive(tree->root, key);
}

void ds_tree_print_recursive(Leaf* leaf) {
    if (leaf == NULL) return;
    ds_tree_print_recursive(leaf->left);
    printf(" %d ", leaf->key);
    ds_tree_print_recursive(leaf->right);
    return;
}

void ds_tree_print(Tree* tree) {
    if (tree == NULL || tree->root == NULL) return;
    printf("[");
    ds_tree_print_recursive(tree->root);
    printf("]\n");
    return;
}

Tree* ds_tree_new_Tree() {
    Tree* new_tree = malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}
