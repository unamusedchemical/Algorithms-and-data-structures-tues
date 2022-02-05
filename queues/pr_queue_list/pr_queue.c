#include "pr_queue.h"
#include <stdlib.h>
#include <stdio.h>

QList *initQueue() {
    QList *ql = malloc(sizeof(QList));
    ql->hightstPr = NULL;
    ql->size = 0;

    return ql;
}

void enqueue(QList *ql, int val) {
    QNode *new = malloc(sizeof(QNode));
    new->val = val;
    new->next = NULL;

    if(ql->hightstPr == NULL) {
        ql->hightstPr = new;
        return;
    }
    if(ql->hightstPr->val <= val) {
        new->next = ql->hightstPr;
        ql->hightstPr = new;
        return;
    }

    QNode *temp = ql->hightstPr;
    while(temp->next && temp->next->val > val) {
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
}

void dequeue(QList *ql) {
    if(ql->hightstPr == NULL) return;
    QNode *temp = ql->hightstPr;
    ql->hightstPr = temp->next;
    free(temp);
}

void display(QList *ql) {
    QNode *temp = ql->hightstPr;
    printf("Highest priority-> ");
    while(temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("<-Lowest priority\n");
}

void destroy(QList *ql) {
    QNode *temp = ql->hightstPr;
    while(ql->hightstPr) {
        temp = ql->hightstPr;
        ql->hightstPr = temp->next;
        free(temp);
    }
    free(ql);
}
