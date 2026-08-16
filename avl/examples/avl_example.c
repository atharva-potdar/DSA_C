#include "../avl.h"
#include <stdio.h>

int main(void)
{
    AVL* avl = avl_new();

    avl_insert(avl, 10);
    avl_insert(avl, 5);
    avl_insert(avl, 15);
    avl_insert(avl, 3);
    avl_insert(avl, 7);
    avl_insert(avl, 12);
    avl_insert(avl, 20);

    printf("inorder: ");
    avl_inorder(avl);

    printf("preorder: ");
    avl_preorder(avl);

    printf("postorder: ");
    avl_postorder(avl);

    printf("min: %d\n", avl_min(avl));
    printf("max: %d\n", avl_max(avl));
    printf("height: %zu\n", avl_height(avl));
    printf("is_empty: %d\n", avl_is_empty(avl));

    printf("search 7: %d\n", avl_search(avl, 7));
    printf("search 99: %d\n", avl_search(avl, 99));

    // Trigger rotations — inserting in ascending order forces rebalancing
    avl_insert(avl, 25);
    avl_insert(avl, 30);
    printf("after inserting 25, 30 (right-right rotation): ");
    avl_inorder(avl);

    avl_delete(avl, 5);
    printf("after delete 5: ");
    avl_inorder(avl);

    avl_delete(avl, 15);
    printf("after delete 15: ");
    avl_inorder(avl);

    avl_delete(avl, 10);
    printf("after delete 10 (root): ");
    avl_inorder(avl);

    printf("height after deletions: %zu\n", avl_height(avl));
    printf("is_empty: %d\n", avl_is_empty(avl));

    avl_free(avl);
    return 0;
}
