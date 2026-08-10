#include "../queue_list.h"
#include <stdio.h>

int main(void) {
    QueueList *queue = queue_list_new();

    queue_list_enqueue(queue, 1);
    queue_list_enqueue(queue, 2);
    queue_list_enqueue(queue, 3);
    queue_list_enqueue(queue, 4);
    queue_list_enqueue(queue, 5);

    printf("len: %zu\n", queue_list_len(queue));
    printf("is_empty: %d\n", queue_list_is_empty(queue));
    printf("peek: %d\n", queue_list_peek(queue));

    printf("dequeue: %d\n", queue_list_dequeue(queue));
    printf("dequeue: %d\n", queue_list_dequeue(queue));
    printf("dequeue: %d\n", queue_list_dequeue(queue));
    printf("dequeue: %d\n", queue_list_dequeue(queue));
    printf("dequeue: %d\n", queue_list_dequeue(queue));

    printf("is_empty: %d\n", queue_list_is_empty(queue));

    queue_list_free(queue);
    return 0;
}
