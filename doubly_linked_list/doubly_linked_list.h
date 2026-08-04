#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef struct DoublyLinkedList DoublyLinkedList;

DoublyLinkedList *doubly_linked_list_new(void);
void doubly_linked_list_clear(DoublyLinkedList *list);
void doubly_linked_list_free(DoublyLinkedList *list);

void doubly_linked_list_push_front(DoublyLinkedList *list, int value);
void doubly_linked_list_push_back(DoublyLinkedList *list, int value);
int doubly_linked_list_pop_front(DoublyLinkedList *list);
int doubly_linked_list_pop_back(DoublyLinkedList *list);

size_t doubly_linked_list_len(const DoublyLinkedList *list);
int doubly_linked_list_is_empty(const DoublyLinkedList *list);
int doubly_linked_list_get(const DoublyLinkedList *list, size_t index);
int doubly_linked_list_contains(const DoublyLinkedList *list, int value);

void doubly_linked_list_insert(DoublyLinkedList *list, size_t index, int value);
int doubly_linked_list_remove(DoublyLinkedList *list, size_t index);

void doubly_linked_list_print(const DoublyLinkedList *list);
void doubly_linked_list_print_reverse(const DoublyLinkedList *list);

#endif
