#ifndef UNTITLED_DYNAMIC_ARR_H
#define UNTITLED_DYNAMIC_ARR_H

typedef struct stack{
    int* vals;
    size_t cap;
    int lenght;
} stack_t;

stack_t* init_stack(size_t cap);
void add(stack_t* stack, int val);
void pop(stack_t* stack);
void print_stack(stack_t* stack);
void back(stack_t stack);

#endif //UNTITLED_DYNAMIC_ARR_H
