#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

struct LinkedList {
    Node *head;
    size_t length;
};

static Node *node_new(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }

    node->value = value;
    node->next = NULL;

    return node;
}

LinkedList *linked_list_new(void) {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->length = 0;

    return list;
}

void linked_list_clear(LinkedList *list) {
    Node *curr = list->head;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->length = 0;
}

void linked_list_free(LinkedList *list) {
    linked_list_clear(list);
    free(list);
}

void linked_list_push_front(LinkedList *list, int value) {
    Node *node = node_new(value);
    node->next = list->head;
    list->head = node;
    list->length++;
}

void linked_list_push_back(LinkedList *list, int value) {
    Node *curr = list->head;
    if (curr == NULL) {
        list->head = node_new(value);
        list->length++;
        return;
    }

    while (curr->next != NULL) {
        curr = curr->next;
    }

    Node *node = node_new(value);
    curr->next = node;
    list->length++;
}

int linked_list_pop_front(LinkedList *list) {
    Node *oldHead = list->head;
    int value = oldHead->value;
    list->head = oldHead->next;
    free(oldHead);
    list->length--;

    return value;
}

int linked_list_pop_back(LinkedList *list) {
    Node *curr = list->head;
    if (curr->next == NULL) {
        int value = curr->value;
        free(curr);
        list->head = NULL;
        list->length--;
        return value;
    }
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    Node *oldTail = curr->next;
    int value = oldTail->value;
    curr->next = NULL;
    free(oldTail);
    list->length--;

    return value;
}

size_t linked_list_len(const LinkedList *list) {
    return list->length;
}

int linked_list_is_empty(const LinkedList *list) {
    return list->length == 0;
}

int linked_list_get(const LinkedList *list, size_t index) {
    const Node *curr = list->head;
    for (size_t i = 0; curr != NULL && i < index; i++, curr = curr->next) {}

    if (curr == NULL) {
        return -1;
    }
    return curr->value;
}

int linked_list_contains(const LinkedList *list, int value) {
    const Node *curr = list->head;
    while (curr != NULL) {
        if (curr->value == value) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void linked_list_insert(LinkedList *list, size_t index, int value) {
    if (index == 0) {
        linked_list_push_front(list, value);
        return;
    }

    Node *curr = list->head;
    for (size_t i = 0; curr != NULL && i < index - 1; i++, curr = curr->next) {}

    if (curr == NULL) {
        return;
    }

    Node *node = node_new(value);
    node->next = curr->next;
    curr->next = node;
    list->length++;
}

int linked_list_remove(LinkedList *list, size_t index) {
    if (index == 0) {
        return linked_list_pop_front(list);
    }

    Node *curr = list->head;

    for (size_t i = 0; curr->next != NULL && i < index - 1; i++, curr = curr->next) {}

    if (curr->next == NULL) {
        return -1;
    }

    Node *removed = curr->next;
    int value = removed->value;
    curr->next = removed->next;
    free(removed);
    list->length--;

    return value;
}

void linked_list_reverse(LinkedList *list) {
    Node *curr = list->head;
    Node *prev = NULL;

    while (curr != NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    list->head = prev;
}

void linked_list_print(const LinkedList *list) {
    const Node *curr = list->head;
    while (curr != NULL) {
        printf("%d", curr->value);
        if (curr->next != NULL) {
            printf(" -> ");
        }
        curr = curr->next;
    }
}
