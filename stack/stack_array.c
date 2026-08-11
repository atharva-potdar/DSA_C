#include "stack_array.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 16

struct StackArray {
    int* data;
    size_t length;
    size_t capacity;
};

StackArray* stack_array_new(void)
{
    StackArray* stack = (StackArray*)malloc(sizeof(StackArray));
    if (stack == NULL) {
        return NULL;
    }
    int* data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (data == NULL) {
        free(stack);
        return NULL;
    }
    stack->data = data;
    stack->length = 0;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

void stack_array_free(StackArray* stack)
{
    free(stack->data);
    free(stack);
}

void stack_array_push(StackArray* stack, int value)
{
    if (stack->length == stack->capacity) {
        stack->capacity <<= 1;
        int* data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
        if (data == NULL) {
            return;
        }
        stack->data = data;
    }
    *(stack->data + stack->length) = value;
    stack->length++;
}

int stack_array_pop(StackArray* stack)
{
    if (stack->length == 0) {
        return -1;
    }
    int value = *(stack->data + stack->length - 1);
    stack->length--;
    return value;
}

int stack_array_peek(const StackArray* stack)
{
    if (stack->length == 0) {
        return -1;
    }
    return *(stack->data + stack->length - 1);
}

size_t stack_array_len(const StackArray* stack)
{
    return stack->length;
}

int stack_array_is_empty(const StackArray* stack)
{
    return stack->length == 0;
}
