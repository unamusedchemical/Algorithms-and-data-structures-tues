#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int *arr;
    unsigned int capacity, front, rear;
} queue_t;

queue_t *initQueue(int capacity);
int isFull(queue_t *q);
int isEmpty(queue_t *q);
void enqueue(queue_t *q, int val);
void dequeue(queue_t *q);
int peek(queue_t *q);
void display(queue_t *q);
//can be done with a singular pointer too
//idk why I'm doing it like this
void destroy(queue_t **q);
#endif
