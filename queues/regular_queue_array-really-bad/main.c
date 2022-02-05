#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//pretty shit implementation
//better do a circular queue or a normal one using linked list
//even if u realloc the memory you will still be wasting a ton of it

int main() {
    queue_t *q1 = initQueue(10);
    enqueue(q1, 12);
    dequeue(q1);
    enqueue(q1, 12);
    display(q1);
    destroy(&q1);
    return 0;
}
