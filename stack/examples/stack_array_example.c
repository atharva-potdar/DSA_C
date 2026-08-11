#include "../stack_array.h"
#include <stdio.h>

int main(void)
{
    StackArray* stack = stack_array_new();

    stack_array_push(stack, 1);
    stack_array_push(stack, 2);
    stack_array_push(stack, 3);
    stack_array_push(stack, 4);
    stack_array_push(stack, 5);

    printf("len: %zu\n", stack_array_len(stack));
    printf("is_empty: %d\n", stack_array_is_empty(stack));
    printf("peek: %d\n", stack_array_peek(stack));

    printf("pop: %d\n", stack_array_pop(stack));
    printf("pop: %d\n", stack_array_pop(stack));
    printf("pop: %d\n", stack_array_pop(stack));
    printf("pop: %d\n", stack_array_pop(stack));
    printf("pop: %d\n", stack_array_pop(stack));

    printf("is_empty: %d\n", stack_array_is_empty(stack));

    stack_array_free(stack);
    return 0;
}
