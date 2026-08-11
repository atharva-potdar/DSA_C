#include "../stack_list.h"
#include <stdio.h>

int main(void)
{
    StackList* stack = stack_list_new();

    stack_list_push(stack, 1);
    stack_list_push(stack, 2);
    stack_list_push(stack, 3);
    stack_list_push(stack, 4);
    stack_list_push(stack, 5);

    printf("len: %zu\n", stack_list_len(stack));
    printf("is_empty: %d\n", stack_list_is_empty(stack));
    printf("peek: %d\n", stack_list_peek(stack));

    printf("pop: %d\n", stack_list_pop(stack));
    printf("pop: %d\n", stack_list_pop(stack));
    printf("pop: %d\n", stack_list_pop(stack));
    printf("pop: %d\n", stack_list_pop(stack));
    printf("pop: %d\n", stack_list_pop(stack));

    printf("is_empty: %d\n", stack_list_is_empty(stack));

    stack_list_free(stack);
    return 0;
}
