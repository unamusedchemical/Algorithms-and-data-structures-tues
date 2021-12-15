#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arr.h"

stack_t* init_stack(size_t cap) {
    if(!cap)
        return NULL;
    stack_t* stack = malloc(sizeof(stack_t));
    stack->cap = cap;
    stack->lenght = 0;
    stack->vals = malloc(sizeof(int) * stack->cap);

    return stack;
}

void add(stack_t* stack, int val) {
    if(stack->lenght == stack->cap) {
        stack->cap*=2;
        stack->vals = realloc(stack->vals, stack->cap);
    }

    stack->vals[stack->lenght++] = val;
}

void pop(stack_t* stack) {
    if(!stack->lenght)
        return;
    stack->lenght--;
}

void print_stack(stack_t* stack) {
    if(!stack->lenght) return;

    for(int i = stack->lenght-1; i >= 0; i--) {
        printf("%d ", stack->vals[i]);
    }
    printf("\n");
}

void back(stack_t stack) {
    printf("%d\n", stack.vals[stack.lenght-1]);
}
