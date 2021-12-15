#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_arr.h"

int main(int argc, char **argv) {
    stack_t* stack = init_stack(15);
    for(int i = 1; i < argc; ++i) {
        if(!strcmp("add", argv[i])) {
            int val;
            if(sscanf(argv[i+1], "%d", &val))
                add(stack, val);
            else 
                printf("No value to add found.\n");
        } else if(!strcmp("pop", argv[i])) {
            pop(stack);
            printf("Element popped!\n");
        } else if(!strcmp("back", argv[i])) {
            back(*stack);
        } else if(!strcmp("print", argv[i])) {
            print_stack(stack);
        }
    }

    free(stack->vals);
    free(stack);

    return 0;
}
