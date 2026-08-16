#ifndef AVL_H
#define AVL_H

#include <stddef.h>

typedef struct AVL AVL;

AVL* avl_new(void);
void avl_free(AVL* avl);

void avl_insert(AVL* avl, int value);
void avl_delete(AVL* avl, int value);
int avl_search(const AVL* avl, int value);

void avl_inorder(const AVL* avl);
void avl_preorder(const AVL* avl);
void avl_postorder(const AVL* avl);

int avl_min(const AVL* avl);
int avl_max(const AVL* avl);

size_t avl_height(const AVL* avl);
int avl_is_empty(const AVL* avl);

#endif
