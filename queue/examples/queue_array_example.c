#include "../queue_array.h"
#include <stdio.h>

int main(void) {
    QueueArray *queue = queue_array_new();

    queue_array_enqueue(queue, 1);
    queue_array_enqueue(queue, 2);
    queue_array_enqueue(queue, 3);
    queue_array_enqueue(queue, 4);
    queue_array_enqueue(queue, 5);

    printf("len: %zu\n", queue_array_len(queue));
    printf("is_empty: %d\n", queue_array_is_empty(queue));
    printf("peek: %d\n", queue_array_peek(queue));

    printf("dequeue: %d\n", queue_array_dequeue(queue));
    printf("dequeue: %d\n", queue_array_dequeue(queue));
    printf("dequeue: %d\n", queue_array_dequeue(queue));
    printf("dequeue: %d\n", queue_array_dequeue(queue));
    printf("dequeue: %d\n", queue_array_dequeue(queue));

    printf("is_empty: %d\n", queue_array_is_empty(queue));

    queue_array_free(queue);
    return 0;
}
