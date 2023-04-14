#include "test_header.h"

static void test_tree_add(Tree* tree) {
    printf("\nCalling tree_add_leaf(...) returns: \n");
    for (int i = 0; i < 200; i++) {
        tree_add(tree, rand() % 1000);
    }
    tree_print(tree);
    tree_print_partial(tree);
}

static void test_tree_remove(Tree* tree, int* num) {
    *num = tree->root->key;
    printf("\nRoot is: %d", *num);
    printf("\nCalling tree_remove() returns: \n");
    tree_remove(tree, *num);
    tree_print(tree);
    tree_print_partial(tree);
}

void test_binary_tree() {
    Tree* tree = ds_new_tree();
    int num = 0;

    printf("Testing Binary Tree\n");
    test_tree_add(tree);
    test_tree_remove(tree, &num);

    tree_destroy(tree);
    printf("\n---------------------------------------------------------\n\n");
}
