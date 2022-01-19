#include <stdio.h>
#include <stdlib.h>

struct list {
    double a, b;
    struct list *next;
};

typedef struct list node_t;

void addFront(node_t **head, double a, double b) {
    node_t *new = malloc(sizeof(node_t));
    new->a = a;
    new->b = b;
    new->next = *head;
    *head = new;
}

void printList(node_t *head) {
    while(head) {
        printf("a: %lf, b: %lf\n", head->a, head->b);
        head = head->next;
    }
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int strictSubset(node_t *head) {
    if(!head || !head->next)
        return 1;

    double ha = head->a, hb = head->b, hna = head->next->a, hnb = head->next->b;
    if(ha > hb)
        swap(&ha, &hb);
    if(hna > hnb)
        swap(&hna, &hnb);

    if((ha <= hna && hb > hnb) || (ha < hna && hb >= hnb)) {
        return 1 && strictSubset(head->next);
    }

    return 0;
}

void freeList(node_t **head) {
    node_t *delete;
    while(*head) {
        delete = *head;
        *head = (*head)->next;
        free(delete);
    }
}

int main() {
    node_t *head = NULL;

    addFront(&head, 4, 5);
    addFront(&head, 7, 3);
    addFront(&head, 1, 10);
    addFront(&head, 1, 10);
    printList(head);

    printf("\n%d\n", strictSubset(head));

    freeList(&head);

    return 0;
}