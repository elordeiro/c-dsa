#include "data_structures.h"

static Leaf* new_leaf(int x) {
    Leaf* new_leaf = malloc(sizeof(Leaf));
    new_leaf->key = x;
    new_leaf->height = 1;
    new_leaf->left = NULL;
    new_leaf->right = NULL;
    return new_leaf;
}
static int max_child_height(Leaf* leaf) {
    if (leaf == NULL) return 0;
    int x = 0;
    int y = 0;
    if (leaf->left != NULL) x = leaf->left->height;
    if (leaf->right != NULL) y = leaf->right->height;
    return (x > y)? x : y;
}

static int get_balance(Leaf* leaf) {
    if (leaf == NULL) return 0;
    int x = 0;
    int y = 0;
    if (leaf->left != NULL) x = leaf->left->height;
    if (leaf->right != NULL) y = leaf->right->height;
    return (x - y);
}

static Leaf* left_rotate(Leaf* x) {
    Leaf* y = x->right;
    Leaf* T2 = NULL; 
    if (y != NULL) T2 = y->left;

    if (y != NULL) y->left = x;
    x->right = T2;
 
    x->height = max_child_height(x) + 1;
    if (y != NULL) y->height = max_child_height(y) + 1;
    
    return y;
}

static Leaf* right_rotate(Leaf* y) {
    Leaf* x = y->left;
    Leaf* T2 = NULL;
    if (x != NULL) T2 = x->right;
 
    if (x != NULL) x->right = y;
    y->left = T2;
    
    y->height = max_child_height(y) + 1;
    if (x != NULL) x->height = max_child_height(x) + 1;
    
    return x;
}

static Leaf* add_recursive(Leaf* leaf, int x){
    if (leaf == NULL) {
        return new_leaf(x);
    }
    if (x < leaf->key) leaf->left = add_recursive(leaf->left, x);
    else if (x > leaf->key) leaf->right = add_recursive(leaf->right, x);
    else return leaf;

    leaf->height = max_child_height(leaf) + 1;
    
    int balance = get_balance(leaf);
  
    // Left Left Case
    if (leaf->left != NULL)
        if (balance > 1 &&  x <  leaf->left->key)
            return right_rotate(leaf);
 
    // Right Right Case
    if (leaf->right != NULL)
        if (balance < -1 && x > leaf->right->key)
            return left_rotate(leaf);
 
    // Left Right Case
    if (leaf->left != NULL) {
        if (balance > 1 && x > leaf->left->key) {
            leaf->left = left_rotate(leaf->left);
            return right_rotate(leaf);
        }
    }
    // Right Left Case
    if (leaf->right != NULL) {
        if (balance < -1 && x < leaf->right->key) {
            leaf->right = right_rotate(leaf->right);
            return left_rotate(leaf);
        }
    }
    return leaf;
}

void tree_add(Tree* tree, int x) {
    if (tree == NULL) {
        tree = ds_new_tree();
        tree->root = new_leaf(x);
        return;
    }
    if (tree->root == NULL) {
        Leaf* new_lf = new_leaf(x);
        tree->root = new_lf;
        return;
    }
    tree->root = add_recursive(tree->root, x);
    return;
}

static Leaf* find_min(Leaf* node) {
    Leaf* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

static Leaf* remove_recursive(Leaf* leaf, int key) {
    if (leaf == NULL) return leaf;

    if (key < leaf->key) leaf->left = remove_recursive(leaf->left, key);
    else if (key > leaf->key) leaf->right = remove_recursive(leaf->right, key);
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
        Leaf* temp = find_min(leaf->right);
        leaf->key = temp->key;
        leaf->right = remove_recursive(leaf->right, temp->key);
    }
    
    leaf->height = max_child_height(leaf) + 1;

    int balance = get_balance(leaf);  
    // Left Left Case
    if (leaf->left != NULL)
        if (balance > 1 && get_balance(leaf->left) >= 0)
            return right_rotate(leaf);
 
    // Left Right Case
    if (leaf->left != NULL)
        if (balance > 1 && get_balance(leaf->left) < 0) {
            leaf->left = left_rotate(leaf->left);
            return right_rotate(leaf);
        }
    // Right Right Case
    if (leaf->right != NULL)
        if (balance < -1 && get_balance(leaf->right) <= 0)
            return left_rotate(leaf);
 
    // Right Left Case
    if (leaf->right != NULL)
        if (balance < -1 && get_balance(leaf->right) > 0) {
            leaf->right = right_rotate(leaf->right);
            return left_rotate(leaf);
        }
    return leaf;
}

// Function to delete a node with a given key from the tree
void tree_remove(Tree* tree, int key) {
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    tree->root = remove_recursive(tree->root, key);
}
//go back to in order traversal
static void print_recursive(Leaf* leaf) {
    if (leaf == NULL) return;
    printf(" %d ", leaf->key);
    print_recursive(leaf->left);
    print_recursive(leaf->right);
    return;
}

// *__Print entire Tree__
void tree_print(Tree* tree) {
    if (tree == NULL || tree->root == NULL) return;
    printf("[");
    print_recursive(tree->root);
    printf("]\n");
    return;
}

// Print the nodes at a specific level of the BST
static void print_level(Leaf* node, int level, int padding, int actual_level, int* total_padding) {
    if (node == NULL || level < 1) {
        return;
    }
    if (level == 1) {
        printf("%3d", node->key);
        (*total_padding) += 3;
        if (actual_level > 1) {
            for (int i = 0; i < padding; i++) {
                if (*total_padding > 288) break;
                printf(" ");
                (*total_padding)++;
            }
        }
        for (int i = 0; i < pow(2, 6 - actual_level) - 1; i++) {
            if (*total_padding > 288) break;
            printf("   ");
            (*total_padding) += 3;
        }
    } else {
        // recursively traverse the left and right subtrees
        print_level(node->left, level - 1, padding, actual_level, total_padding);
        print_level(node->right, level - 1, padding, actual_level, total_padding);
    }
}

static void print_branches(int level, int padding, int actual_level, int* total_padding) {
    if (level < 1) {
        return;
    }
    if (level == 1) {
        printf("/ \\");
        (*total_padding) += 3;
        if (actual_level > 1) {
            for (int i = 0; i < padding; i++) {
                if (*total_padding > 288) break;
                printf(" ");
                (*total_padding)++;
            }
        }
        for (int i = 0; i < pow(2, 6 - actual_level) - 1; i++) {
            if (*total_padding > 288) break;
            printf("   ");
            (*total_padding) += 3;
        }
    } else {
        // recursively traverse the left and right subtrees
        print_branches(level - 1, padding, actual_level, total_padding);
        print_branches(level - 1, padding, actual_level, total_padding);
    }
}

void tree_print_partial(Tree* tree) {
    int height = 5;
    int padding = 384;
    int prepadding;
    int i;
    int total_padding = 0;
    // print each level of the BST
    for (int level = 0; level <= height + 1; level++) {
        int a = (int) (pow(2, (6 - (level+1))) - 1) * 3;
        int b = (int) (pow(2, (6 - (level+1))) - 1) * 6;
        prepadding = a+b+4;
        if (level > 0) {
            for (i = 0; i < prepadding; i++) {
                printf(" ");
            }
        }
        total_padding = prepadding;
        print_level(tree->root, level, padding, level, &total_padding);
        if (level > 0) {
            printf("\n");
            for (i = 0; i < prepadding; i++) {
                printf(" ");
            }
            total_padding = prepadding;
            print_branches(level, padding, level, &total_padding);
            printf("\n");
        }
        padding /= 2;
    }
}

static void destroy_recursive(Leaf* leaf) {
    if (leaf == NULL) return;
    destroy_recursive(leaf->left);
    destroy_recursive(leaf->right);
    free(leaf);
    leaf = NULL;
    return;
}

void tree_destroy(Tree* tree) {
    destroy_recursive(tree->root);
    free(tree);
    tree = NULL;
    return;
}

// **__Create a new Tree node__
// **__Tree root is initiallized to NULL__
Tree* ds_new_tree() {
    Tree* new_tree = malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}
