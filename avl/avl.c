#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

struct AVL {
    Node* root;
};

AVL* avl_new(void)
{
    AVL* avl = (AVL*)malloc(sizeof(AVL));
    if (avl == NULL) {
        return NULL;
    }
    avl->root = NULL;
    return avl;
}

static void avl_free_helper(Node* node)
{
    if (node == NULL) {
        return;
    }
    avl_free_helper(node->left);
    avl_free_helper(node->right);
    free(node);
}

void avl_free(AVL* avl)
{
    avl_free_helper(avl->root);
    free(avl);
}

static Node* node_new(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static int node_height(const Node* node)
{
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

static void node_update_height(Node* node)
{
    int left = node_height(node->left);
    int right = node_height(node->right);
    node->height = 1 + (left > right ? left : right);
}

static int node_balance_factor(const Node* node)
{
    return node_height(node->left) - node_height(node->right);
}

static Node* rotate_right(Node* node)
{
    Node* left = node->left;
    node->left = left->right;
    left->right = node;
    node_update_height(node);
    node_update_height(left);
    return left;
}

static Node* rotate_left(Node* node)
{
    Node* right = node->right;
    node->right = right->left;
    right->left = node;
    node_update_height(node);
    node_update_height(right);
    return right;
}

static Node* rebalance(Node* node)
{
    node_update_height(node);
    int balance = node_balance_factor(node);
    if (balance > 1) {
        if (node_balance_factor(node->left) < 0) {
            node->left = rotate_left(node->left);
        }
        return rotate_right(node);
    }
    if (balance < -1) {
        if (node_balance_factor(node->right) > 0) {
            node->right = rotate_right(node->right);
        }
        return rotate_left(node);
    }
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
    } else {
        return node;
    }
    return rebalance(node);
}

void avl_insert(AVL* avl, int value)
{
    avl->root = insert_helper(avl->root, value);
}

static Node* avl_min_node(Node* node)
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
        const Node* successor = avl_min_node(node->right);
        node->value = successor->value;
        node->right = delete_helper(node->right, successor->value);
    }
    return rebalance(node);
}

void avl_delete(AVL* avl, int value)
{
    avl->root = delete_helper(avl->root, value);
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

int avl_search(const AVL* avl, int value)
{
    return search_helper(avl->root, value);
}

static void avl_inorder_helper(const Node* node)
{
    if (node == NULL) {
        return;
    }
    avl_inorder_helper(node->left);
    printf("%d ", node->value);
    avl_inorder_helper(node->right);
}

void avl_inorder(const AVL* avl)
{
    avl_inorder_helper(avl->root);
    printf("\n");
}

static void avl_preorder_helper(const Node* node)
{
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    avl_preorder_helper(node->left);
    avl_preorder_helper(node->right);
}

void avl_preorder(const AVL* avl)
{
    avl_preorder_helper(avl->root);
    printf("\n");
}

static void avl_postorder_helper(const Node* node)
{
    if (node == NULL) {
        return;
    }
    avl_postorder_helper(node->left);
    avl_postorder_helper(node->right);
    printf("%d ", node->value);
}

void avl_postorder(const AVL* avl)
{
    avl_postorder_helper(avl->root);
    printf("\n");
}

static int avl_min_helper(const Node* node)
{
    if (node->left == NULL) {
        return node->value;
    }
    return avl_min_helper(node->left);
}

int avl_min(const AVL* avl)
{
    if (avl->root == NULL) {
        return -1;
    }
    return avl_min_helper(avl->root);
}

static int avl_max_helper(const Node* node)
{
    if (node->right == NULL) {
        return node->value;
    }
    return avl_max_helper(node->right);
}

int avl_max(const AVL* avl)
{
    if (avl->root == NULL) {
        return -1;
    }
    return avl_max_helper(avl->root);
}

size_t avl_height(const AVL* avl)
{
    if (avl->root == NULL) {
        return 0;
    }
    return (size_t)avl->root->height + 1;
}

int avl_is_empty(const AVL* avl)
{
    return avl->root == NULL;
}
