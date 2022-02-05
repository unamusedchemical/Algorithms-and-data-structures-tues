#include <stdio.h>
#include "queue.h"

int main() {
    queue_t *q1 = initQueue(10);
    enqueue(q1, 12);
    enqueue(q1, 13);
    enqueue(q1, 14);
    printf("%d ", front(q1));
    printf("%d\n", rear(q1));
    dequeue(q1);
    dequeue(q1);
    dequeue(q1);
    display(q1);
    return 0;
}
