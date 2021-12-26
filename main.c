#include"dyn_arr.h"
#include"hash.h"
#include"actions.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define ACTION_NUM 11

void list_stack(stack_t *s) {
	for (size_t i = 0; i < s->size; i++)
	{
		printf("%.2lf ", s->arr[i]);
	}
	printf("\n");
}

void map(tableV_t *table) {
    void (*stack_funcs[ACTION_NUM])(stack_t *) = {&list_stack, &pop, &printFront, &printBack, &addition, &subtraction, &increment, &decrement, &multiplication, &division, &power};
    char commands[ACTION_NUM][2] = {{'l'},{'p'},{'f'},{'b'},{'+'},{'-'},{"++"},{"--"},{'*'},{'/'},{'^'}};

    for(int i = 0; i < ACTION_NUM; ++i) {
        put(table, commands[i], (*stack_funcs[i]));
    }
}

int main() {
	stack_t *s = init(5);
    tableV_t *variables = init_table(5);
    tableV_t *actions = init_table(10);
    map(actions);
    char *buf = malloc(sizeof(char) * 256);

	while(1) {
        buf[0] = '\n';
        scanf("%s", buf);
		if (isdigit(buf[0]))
		{
			push_back(s, atof(buf));
			continue;
        } else if(contains(actions, buf)){
            void (*f)(stack_t *) = get(actions, buf);
            f(s);
        } else if(buf[0] == '@') {
            create_var(s, variables, buf);
        } else if(buf[0] == '{') {
            check_var(s, variables, buf);
        } else if(!strcmp("exit", buf)) {
            list_stack(s);
            break;
        } else {
			fprintf(stderr, "Invalid operation!\n Unknown '%c'", buf[0]);
			break;
		}
	}
	destroy_stack(s);

	return 0;
}