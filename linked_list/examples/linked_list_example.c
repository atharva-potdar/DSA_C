#include "../linked_list.h"
#include <stdio.h>

int main(void) {
    LinkedList *list = linked_list_new();

    linked_list_push_back(list, 1);
    linked_list_push_back(list, 2);
    linked_list_push_back(list, 3);
    linked_list_push_back(list, 4);
    linked_list_push_back(list, 5);

    printf("Initial: ");
    linked_list_print(list);
    printf("\n");

    linked_list_push_front(list, 0);
    linked_list_push_back(list, 6);

    printf("After push: ");
    linked_list_print(list);
    printf("\n");

    linked_list_pop_front(list);
    linked_list_pop_back(list);

    printf("After pop: ");
    linked_list_print(list);
    printf("\n");

    linked_list_insert(list, 2, 99);

    printf("After insert 99 at index 2: ");
    linked_list_print(list);
    printf("\n");

    linked_list_remove(list, 2);

    printf("After remove 99 from index 2: ");
    linked_list_print(list);
    printf("\n");

    linked_list_reverse(list);

    printf("After reversing list: ");
    linked_list_print(list);
    printf("\n");

    linked_list_reverse(list);

    printf("After reversing the reversed list: ");
    linked_list_print(list);
    printf("\n");

    linked_list_free(list);
    return 0;
}
