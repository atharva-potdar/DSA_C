#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

struct DoublyLinkedList {
    Node* head;
    Node* tail;
    size_t length;
};

static Node* node_new(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

DoublyLinkedList* doubly_linked_list_new(void)
{
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void doubly_linked_list_clear(DoublyLinkedList* list)
{
    Node* curr = list->head;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void doubly_linked_list_free(DoublyLinkedList* list)
{
    doubly_linked_list_clear(list);
    free(list);
}

void doubly_linked_list_push_front(DoublyLinkedList* list, int value)
{
    Node* node = node_new(value);
    if (node == NULL) {
        return;
    }
    node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = node;
    } else {
        list->tail = node;
    }
    list->head = node;
    list->length++;
}

void doubly_linked_list_push_back(DoublyLinkedList* list, int value)
{
    Node* node = node_new(value);
    if (node == NULL) {
        return;
    }
    node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->length++;
}

int doubly_linked_list_pop_front(DoublyLinkedList* list)
{
    Node* oldHead = list->head;
    int value = oldHead->value;
    list->head = oldHead->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(oldHead);
    list->length--;
    return value;
}

int doubly_linked_list_pop_back(DoublyLinkedList* list)
{
    Node* oldTail = list->tail;
    int value = oldTail->value;
    list->tail = oldTail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(oldTail);
    list->length--;
    return value;
}

size_t doubly_linked_list_len(const DoublyLinkedList* list)
{
    return list->length;
}

int doubly_linked_list_is_empty(const DoublyLinkedList* list)
{
    return list->length == 0;
}

int doubly_linked_list_get(const DoublyLinkedList* list, size_t index)
{
    const Node* curr = list->head;

    for (size_t i = 0; curr != NULL && i < index; i++, curr = curr->next) { }

    if (curr == NULL) {
        return -1;
    }
    return curr->value;
}

int doubly_linked_list_contains(const DoublyLinkedList* list, int value)
{
    const Node* curr = list->head;

    while (curr != NULL) {
        if (curr->value == value) {
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}

void doubly_linked_list_insert(DoublyLinkedList* list, size_t index, int value)
{
    if (index == 0) {
        doubly_linked_list_push_front(list, value);
        return;
    }

    Node* curr = list->head;
    for (size_t i = 0; curr != NULL && i < index - 1; i++, curr = curr->next) { }

    if (curr == NULL) {
        return;
    }

    Node* node = node_new(value);
    if (node == NULL) {
        return;
    }
    node->next = curr->next;
    node->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = node;
    } else {
        list->tail = node;
    }
    curr->next = node;
    list->length++;
}

int doubly_linked_list_remove(DoublyLinkedList* list, size_t index)
{
    if (index == 0) {
        return doubly_linked_list_pop_front(list);
    }

    Node* curr = list->head;

    for (size_t i = 0; curr->next != NULL && i < index - 1; i++, curr = curr->next) { }

    if (curr->next == NULL) {
        return -1;
    }

    Node* removed = curr->next;
    int value = removed->value;
    curr->next = removed->next;
    if (removed->next != NULL) {
        removed->next->prev = curr;
    } else {
        list->tail = curr;
    }
    free(removed);
    list->length--;

    return value;
}

void doubly_linked_list_print(const DoublyLinkedList* list)
{
    const Node* curr = list->head;
    while (curr != NULL) {
        printf("%d", curr->value);
        if (curr->next != NULL) {
            printf(" -> ");
        }
        curr = curr->next;
    }
}

void doubly_linked_list_print_reverse(const DoublyLinkedList* list)
{
    const Node* curr = list->tail;
    while (curr != NULL) {
        printf("%d", curr->value);
        if (curr->prev != NULL) {
            printf(" <- ");
        }
        curr = curr->prev;
    }
}
