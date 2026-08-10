#include "queue_array.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 16

struct QueueArray {
    int *data;
    size_t head;
    size_t tail;
    size_t length;
    size_t capacity;
};

QueueArray *queue_array_new(void) {
    QueueArray *queue = (QueueArray *) malloc(sizeof(QueueArray));
    if (queue == NULL) {
        return NULL;
    }
    int *data = (int *) malloc(INITIAL_CAPACITY * sizeof(int));
    if (data == NULL) {
        free(queue);
        return NULL;
    }
    queue->data = data;
    queue->head = 0;
    queue->tail = 0;
    queue->length = 0;
    queue->capacity = INITIAL_CAPACITY;
    return queue;
}

void queue_array_free(QueueArray *queue) {
    free(queue->data);
    free(queue);
}

void queue_array_enqueue(QueueArray *queue, int value) {
    if (queue->length == queue->capacity) {
        size_t old_capacity = queue->capacity;
        size_t new_capacity = queue->capacity << 1;
        int *data = (int *) realloc(queue->data, new_capacity * sizeof(int));
        if (data == NULL) {
            return;
        }
        if (queue->head > 0) {
            for (size_t i = 0; i < queue->tail; i++) {
                *(data + old_capacity + i) = *(data + i);
            }
            queue->tail = old_capacity + queue->tail;
        } else {
            queue->tail = old_capacity;
        }
        queue->data = data;
        queue->capacity = new_capacity;
    }
    *(queue->data + queue->tail) = value;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->length++;
}

int queue_array_dequeue(QueueArray *queue) {
    if (queue->length == 0) {
        return -1;
    }
    int value = *(queue->data + queue->head);
    queue->head = (queue->head + 1) % queue->capacity;
    queue->length--;
    return value;
}

int queue_array_peek(const QueueArray *queue) {
    if (queue->length == 0) {
        return -1;
    }
    return *(queue->data + queue->head);
}

size_t queue_array_len(const QueueArray *queue) {
    return queue->length;
}

int queue_array_is_empty(const QueueArray *queue) {
    return queue->length == 0;
}
