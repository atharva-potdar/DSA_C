#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <stddef.h>

typedef struct StackList StackList;

StackList *stack_list_new(void);
void stack_list_free(StackList *stack);

void stack_list_push(StackList *stack, int value);
int stack_list_pop(StackList *stack);

int stack_list_peek(const StackList *stack);
size_t stack_list_len(const StackList *stack);
int stack_list_is_empty(const StackList *stack);

#endif
