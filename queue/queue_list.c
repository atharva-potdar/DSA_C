#include "queue_list.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

struct QueueList {
    Node* head;
    Node* tail;
    size_t length;
};

QueueList* queue_list_new(void)
{
    QueueList* queue = (QueueList*)malloc(sizeof(QueueList));
    if (queue == NULL) {
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;
    return queue;
}

void queue_list_free(QueueList* queue)
{
    Node* node = queue->head;
    while (node != NULL) {
        Node* next = node->next;
        free(node);
        node = next;
    }
    free(queue);
}

static Node* node_new(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void queue_list_enqueue(QueueList* queue, int value)
{
    Node* node = node_new(value);
    if (node == NULL) {
        return;
    }
    if (queue->tail != NULL) {
        queue->tail->next = node;
    } else {
        queue->head = node;
    }
    queue->tail = node;
    queue->length++;
}

int queue_list_dequeue(QueueList* queue)
{
    if (queue->head == NULL) {
        return -1;
    }
    Node* node = queue->head;
    int value = node->value;
    queue->head = node->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(node);
    queue->length--;
    return value;
}

int queue_list_peek(const QueueList* queue)
{
    if (queue->head == NULL) {
        return -1;
    }
    return queue->head->value;
}

size_t queue_list_len(const QueueList* queue)
{
    return queue->length;
}

int queue_list_is_empty(const QueueList* queue)
{
    return queue->length == 0;
}
