#ifndef PR_QUEUE_H
#define PR_QUEUE_H

typedef struct QNode {
    //the higher the value the higher the priority
    int val;
    struct QNode *next;
//    struct QueueNode *prev;
} QNode;

typedef struct QList {

    QNode *hightstPr;
    unsigned size;
} QList;
//there won't be any isFull or isEmpty functions here since we are using linked list
QList *initQueue();
void enqueue(QList *ql, int val);
void dequeue(QList *ql);
void display(QList *ql);
void destroy(QList *ql);

#endif
