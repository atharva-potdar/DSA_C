#include "../bst.h"
#include <stdio.h>

int main(void) {
    BST *bst = bst_new();

    bst_insert(bst, 10);
    bst_insert(bst, 5);
    bst_insert(bst, 15);
    bst_insert(bst, 3);
    bst_insert(bst, 7);
    bst_insert(bst, 12);
    bst_insert(bst, 20);

    printf("inorder: ");
    bst_inorder(bst);

    printf("preorder: ");
    bst_preorder(bst);

    printf("postorder: ");
    bst_postorder(bst);

    printf("min: %d\n", bst_min(bst));
    printf("max: %d\n", bst_max(bst));
    printf("height: %zu\n", bst_height(bst));
    printf("is_empty: %d\n", bst_is_empty(bst));

    printf("search 7: %d\n", bst_search(bst, 7));
    printf("search 99: %d\n", bst_search(bst, 99));

    bst_delete(bst, 5);
    printf("after delete 5 (leaf): ");
    bst_inorder(bst);

    bst_delete(bst, 15);
    printf("after delete 15 (two children): ");
    bst_inorder(bst);

    bst_delete(bst, 10);
    printf("after delete 10 (root): ");
    bst_inorder(bst);

    printf("is_empty: %d\n", bst_is_empty(bst));

    bst_free(bst);
    return 0;
}
