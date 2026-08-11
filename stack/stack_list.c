#include "stack_list.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct StackList {
    Node *head;
    size_t length;
};

StackList *stack_list_new(void) {
    StackList *stack = (StackList *) malloc(sizeof(StackList));
    if (stack == NULL) {
        return NULL;
    }

    stack->head = NULL;
    stack->length = 0;

    return stack;
}

void stack_list_free(StackList *stack) {
    Node *node = stack->head;
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }
    free(stack);
}

static Node *node_new(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) { return NULL; }
    node->value = value;
    node->next = NULL;
    return node;
}

void stack_list_push(StackList *stack, int value) {
    Node *node = node_new(value);
    if (node == NULL) { return; }
    node->next = stack->head;
    stack->head = node;
    stack->length++;
}

int stack_list_pop(StackList *stack) {
    if (stack->head == NULL) {
        return -1;
    }
    Node *node = stack->head;
    stack->head = node->next;
    int value = node->value;
    free(node);
    stack->length--;
    return value;
}

int stack_list_peek(const StackList *stack) {
    if (stack->head == NULL) {
        return -1;
    }
    return stack->head->value;
}

size_t stack_list_len(const StackList *stack) {
    return stack->length;
}

int stack_list_is_empty(const StackList *stack) {
    return stack->length == 0;
}
