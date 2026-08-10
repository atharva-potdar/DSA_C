#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stddef.h>

typedef struct QueueArray QueueArray;

QueueArray *queue_array_new(void);
void queue_array_free(QueueArray *queue);

void queue_array_enqueue(QueueArray *queue, int value);
int queue_array_dequeue(QueueArray *queue);

int queue_array_peek(const QueueArray *queue);
size_t queue_array_len(const QueueArray *queue);
int queue_array_is_empty(const QueueArray *queue);

#endif
