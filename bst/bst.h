#ifndef BST_H
#define BST_H

#include <stddef.h>

typedef struct BST BST;

BST *bst_new(void);
void bst_free(BST *bst);

void bst_insert(BST *bst, int value);
void bst_delete(BST *bst, int value);
int bst_search(const BST *bst, int value);

void bst_inorder(const BST *bst);
void bst_preorder(const BST *bst);
void bst_postorder(const BST *bst);

int bst_min(const BST *bst);
int bst_max(const BST *bst);

size_t bst_height(const BST *bst);
int bst_is_empty(const BST *bst);

#endif
