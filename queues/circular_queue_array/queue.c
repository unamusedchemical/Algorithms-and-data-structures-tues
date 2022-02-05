#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t *initQueue(int capacity) {
    if(capacity < 1) {
        exit(-1);
    }

    queue_t *queue = malloc(sizeof(queue_t));
    queue->arr = calloc(sizeof(queue_t), capacity);
    queue->front = queue->rear = -1;
    queue->size = 0;

    return queue;
}

int isFull(queue_t *queue) {
    if(queue->front == queue->rear + 1 || (queue->front == 0 && queue->rear == queue->capacity - 1))
        return 1;
    return 0;
}

int isEmpty(queue_t *queue) {
    if(queue->size == 0)
        return 1;
    return 0;
}

void enqueue(queue_t *queue, int val) {
    if(isFull(queue)) return;
    if(queue->front == -1) queue->front = 0;
    queue->size++;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = val;
}

void dequeue(queue_t *queue) {
    if(isEmpty(queue)) return;
    queue->size--;
    queue->front = (queue->front + 1) % queue->capacity;
}

int front(queue_t *queue) {
    if(queue->front == -1) {
        return INT_MIN;
    }

    return queue->arr[queue->front];
}

int rear(queue_t *queue) {
    if(queue->rear == -1) {
        return INT_MIN;
    }

    return queue->arr[queue->rear];
}

void display(queue_t *queue) {
    if(isEmpty(queue)) {
        printf("Empty queue");
        return;
    }

    unsigned int i;
    for(i = queue->front; i != queue->rear; i = (i+1)%queue->capacity) {
        printf("%d ", queue->arr[i]);
    }
    printf("%d\n", queue->arr[queue->rear]);
}

void destroy(queue_t **queue) {
    free((**queue).arr);
    free(*queue);
}
