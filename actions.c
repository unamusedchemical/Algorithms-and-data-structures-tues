#include"actions.h"
#include<math.h>
#include<stdio.h>

void addition(stack_t *s) {
    if(s->size >= 2) {
        s->arr[s->size-2] += back(s);
        pop(s); 
    }
}
void subtraction(stack_t *s) {
    if(s->size >= 2) {
        s->arr[s->size-2] -= back(s);
        pop(s);
    }    
}
void division(stack_t *s) {
    if(s->size >= 2) {
        s->arr[s->size-2] /= back(s);
        pop(s);
    }    
}
void multiplication(stack_t *s) {                
    if(s->size >= 2) {
        s->arr[s->size-2] *= back(s);
        pop(s);
    }
}
void increment(stack_t *s) {
    if(s->size >= 1) 
        s->arr[s->size-1]++;
}
void decrement(stack_t *s) {
    if(s->size >= 1)
        s->arr[s->size-1]--;
}
void power(stack_t *s) {
    if(s->size >= 2) {
        s->arr[s->size-2] =pow(s->arr[s->size-2], s->arr[s->size-1]);
        pop(s);
    }
}
void printBack(stack_t *s) {
    printf("%d\n", back(s));
}
void printFront(stack_t *s) {
    printf("%d\n", front(s));
}
