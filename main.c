#include <stdio.h>
#include "dynamic_arr.h"

int main() {
    stack_t* stack = init_stack(2);
    add(stack, 5);
    add(stack, 10);
    add(stack, 15);
    pop(stack);
    print_stack(stack);
    back(*stack);

    return 0;
}
