#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <stddef.h>

typedef struct QueueList QueueList;

QueueList *queue_list_new(void);
void queue_list_free(QueueList *queue);

void queue_list_enqueue(QueueList *queue, int value);
int queue_list_dequeue(QueueList *queue);

int queue_list_peek(const QueueList *queue);
size_t queue_list_len(const QueueList *queue);
int queue_list_is_empty(const QueueList *queue);

#endif
