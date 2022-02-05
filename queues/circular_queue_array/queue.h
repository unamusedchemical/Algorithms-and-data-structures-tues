#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int *arr;
    unsigned int size, capacity, front, rear;
} queue_t;

queue_t *initQueue(int capacity);
int isFull(queue_t *queue);
int isEmpty(queue_t *queue);
void enqueue(queue_t *queue, int val);
void dequeue(queue_t *queue);
int front(queue_t *queue);
int rear(queue_t *queue);
void display(queue_t *queue);
void destroy(queue_t **queue);

#endif
