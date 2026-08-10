#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stddef.h>

typedef struct StackArray StackArray;

StackArray *stack_array_new(void);
void stack_array_free(StackArray *stack);

void stack_array_push(StackArray *stack, int value);
int stack_array_pop(StackArray *stack);

int stack_array_peek(const StackArray *stack);
size_t stack_array_len(const StackArray *stack);
int stack_array_is_empty(const StackArray *stack);

#endif
