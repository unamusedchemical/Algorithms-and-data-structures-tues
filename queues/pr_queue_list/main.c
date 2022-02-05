#include "pr_queue.h"
#include <stdio.h>

int main() {
    QList *ql = initQueue();
    enqueue(ql, 12);
    enqueue(ql, 123);
    dequeue(ql);
    display(ql);
    destroy(ql);

    return 0;
}
