#include "test_header.h"

static void test_ds_tree_add_leaf(Tree* tree) {
    printf("\nCalling ds_tree_add_leaf(...) returns: \n");
    for (int i = 0; i < 20; i++) {
        ds_tree_add_leaf(tree, rand() % 1000);
    }
    ds_tree_print(tree);
    ds_tree_print_partial(tree);
}

static void test_ds_tree_remove(Tree* tree, int* num) {
    *num = tree->root->key;
    printf("\nRoot is: %d", tree->root->key);
    printf("\nCalling ds_tree_remove() returns: \n");
    ds_tree_remove(tree, *num);
    ds_tree_print(tree);
    ds_tree_print_partial(tree);
}

void test_binary_tree() {
    Tree* tree = ds_tree_new_Tree();
    int num = 0;

    printf("Testing Binary Tree\n");
    test_ds_tree_add_leaf(tree);
    test_ds_tree_remove(tree, &num);

    ds_tree_destroy(tree);
    printf("\n---------------------------------------------------------\n\n");
}
