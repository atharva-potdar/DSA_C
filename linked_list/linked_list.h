#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct LinkedList LinkedList;

LinkedList *linked_list_new(void);
void linked_list_clear(LinkedList *list);
void linked_list_free(LinkedList *list);

void linked_list_push_front(LinkedList *list, int value);
void linked_list_push_back(LinkedList *list, int value);
int linked_list_pop_front(LinkedList *list);
int linked_list_pop_back(LinkedList *list);

int linked_list_get(const LinkedList *list, size_t index);
int linked_list_contains(const LinkedList *list, int value);
size_t linked_list_len(const LinkedList *list);
int linked_list_is_empty(const LinkedList *list);
void linked_list_print(const LinkedList *list);

void linked_list_insert(LinkedList *list, size_t index, int value);
int linked_list_remove(LinkedList *list, size_t index);
void linked_list_reverse(LinkedList *list);

#endif
