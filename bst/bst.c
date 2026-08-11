#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

struct BST {
    Node* root;
};

BST* bst_new(void)
{
    BST* bst = (BST*)malloc(sizeof(BST));
    if (bst == NULL) {
        return NULL;
    }

    bst->root = NULL;
    return bst;
}

static void bst_free_helper(Node* node)
{
    if (node == NULL) {
        return;
    }
    bst_free_helper(node->left);
    bst_free_helper(node->right);
    free(node);
}

void bst_free(BST* bst)
{
    bst_free_helper(bst->root);
    free(bst);
}

static Node* node_new(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static Node* insert_helper(Node* node, int value)
{
    if (node == NULL) {
        return node_new(value);
    }
    if (value < node->value) {
        node->left = insert_helper(node->left, value);
    } else if (value > node->value) {
        node->right = insert_helper(node->right, value);
    }
    return node;
}

void bst_insert(BST* bst, int value)
{
    bst->root = insert_helper(bst->root, value);
}

static Node* bst_min_node(Node* node)
{
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

static Node* delete_helper(Node* node, int value)
{
    if (node == NULL) {
        return NULL;
    }
    if (value < node->value) {
        node->left = delete_helper(node->left, value);
    } else if (value > node->value) {
        node->right = delete_helper(node->right, value);
    } else {
        if (node->left == NULL) {
            Node* right = node->right;
            free(node);
            return right;
        }
        if (node->right == NULL) {
            Node* left = node->left;
            free(node);
            return left;
        }
        const Node* successor = bst_min_node(node->right);
        node->value = successor->value;
        node->right = delete_helper(node->right, successor->value);
    }
    return node;
}

void bst_delete(BST* bst, int value)
{
    bst->root = delete_helper(bst->root, value);
}

static int search_helper(const Node* node, int value)
{
    if (node == NULL) {
        return 0;
    }
    if (value == node->value) {
        return 1;
    }
    if (value < node->value) {
        return search_helper(node->left, value);
    }
    return search_helper(node->right, value);
}

int bst_search(const BST* bst, int value)
{
    return search_helper(bst->root, value);
}

static void bst_inorder_helper(const Node* node)
{
    if (node == NULL) {
        return;
    }
    bst_inorder_helper(node->left);
    printf("%d ", node->value);
    bst_inorder_helper(node->right);
}

void bst_inorder(const BST* bst)
{
    bst_inorder_helper(bst->root);
    printf("\n");
}

static void bst_preorder_helper(const Node* node)
{
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    bst_preorder_helper(node->left);
    bst_preorder_helper(node->right);
}

void bst_preorder(const BST* bst)
{
    bst_preorder_helper(bst->root);
    printf("\n");
}

static void bst_postorder_helper(const Node* node)
{
    if (node == NULL) {
        return;
    }
    bst_postorder_helper(node->left);
    bst_postorder_helper(node->right);
    printf("%d ", node->value);
}

void bst_postorder(const BST* bst)
{
    bst_postorder_helper(bst->root);
    printf("\n");
}

static int bst_min_helper(const Node* node)
{
    if (node->left == NULL) {
        return node->value;
    }
    return bst_min_helper(node->left);
}

int bst_min(const BST* bst)
{
    if (bst->root == NULL) {
        return -1;
    }
    return bst_min_helper(bst->root);
}

static int bst_max_helper(const Node* node)
{
    if (node->right == NULL) {
        return node->value;
    }
    return bst_max_helper(node->right);
}

int bst_max(const BST* bst)
{
    if (bst->root == NULL) {
        return -1;
    }
    return bst_max_helper(bst->root);
}

static size_t bst_height_helper(const Node* node)
{
    if (node == NULL) {
        return 0;
    }
    size_t left = bst_height_helper(node->left);
    size_t right = bst_height_helper(node->right);
    return 1 + (left > right ? left : right);
}

size_t bst_height(const BST* bst)
{
    return bst_height_helper(bst->root);
}

int bst_is_empty(const BST* bst)
{
    return bst->root == NULL;
}
