#include "../doubly_linked_list.h"
#include <stdio.h>

int main(void) {
    DoublyLinkedList *list = doubly_linked_list_new();

    doubly_linked_list_push_back(list, 1);
    doubly_linked_list_push_back(list, 2);
    doubly_linked_list_push_back(list, 3);
    doubly_linked_list_push_back(list, 4);
    doubly_linked_list_push_back(list, 5);

    printf("Initial: ");
    doubly_linked_list_print(list);
    printf("\n");

    printf("Initial reversed: ");
    doubly_linked_list_print_reverse(list);
    printf("\n");

    doubly_linked_list_push_front(list, 0);
    doubly_linked_list_push_back(list, 6);

    printf("After push: ");
    doubly_linked_list_print(list);
    printf("\n");

    doubly_linked_list_pop_front(list);
    doubly_linked_list_pop_back(list);

    printf("After pop: ");
    doubly_linked_list_print(list);
    printf("\n");

    doubly_linked_list_insert(list, 2, 99);

    printf("After insert 99 at index 2: ");
    doubly_linked_list_print(list);
    printf("\n");

    doubly_linked_list_remove(list, 2);

    printf("After remove 99 from index 2: ");
    doubly_linked_list_print(list);
    printf("\n");

    printf("After remove 99 from index 2 reversed: ");
    doubly_linked_list_print_reverse(list);
    printf("\n");

    doubly_linked_list_free(list);
    return 0;
}
