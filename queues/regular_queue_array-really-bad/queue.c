#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

queue_t *initQueue(int capacity) {
    if(capacity < 1) exit(-1);

    queue_t *q = malloc(sizeof(queue_t));
    q->capacity = capacity;
    q->arr = calloc(sizeof(int), capacity);
    q->front = q->rear = -1;

    return q;
}

int isFull(queue_t *q) {
    if(q->rear == q->capacity-1) return 1;
    return 0;
}

int isEmpty(queue_t *q) {
    if(q->front == -1 || q->front > q->rear) return 1;
    return 0;
}

void enqueue(queue_t *q, int val) {
    if(isFull(q)) return;
    if(q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear] = val;
}

void dequeue(queue_t *q) {
    if(isEmpty(q)) return;
    q->front++;
}

int peek(queue_t *q) {
    if(isEmpty(q)) return INT_MIN;
    return q->arr[q->front];
}

void display(queue_t *q) {
    if(isEmpty(q)) return;

    for(unsigned int i = q->front; i <= q->rear; ++i) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void destroy(queue_t **q) {
    free((*q)->arr);
    free(*q);
}
