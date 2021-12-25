#include"dyn_arr.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

void list_stack(stack_t *s) {
	for (size_t i = 0; i < s->size; i++)
	{
		printf("%.2lf ", s->arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv) {
	stack_t *s = init(5);

	for (size_t i = 1; i < argc; i++)
	{
		if (isdigit(argv[i][0]))
		{
			push_back(s, atof(argv[i]));
			continue;
		}
		//change to if-else
		switch (argv[i][0])
		{
		case 'l':
			list_stack(s);
			break;
		case 'p':
			pop(s);
			break;
		case 'f':
			printf("%.2lf\n", front(s));
			break;
		case 'b':
			printf("%.2lf\n", back(s));
			break;
		case '+':
			if(argv[i][1] == '+') {
				s->arr[s->size-1]++;
				break; 
			}
			if(s->size >= 2)
				s->arr[s->size-2] += back(s);
			pop(s);
			break;
		case '-':
			if(argv[i][1] == '-') {
				s->arr[s->size-1]--;
				break; 
			}
			if(s->size >= 2)
				s->arr[s->size-2] -= back(s);
			pop(s);
			break;
		case 'k':
			printf("adasd");
			if(s->size >= 2)
				s->arr[s->size-2] *= back(s);
			pop(s);
			break;
		case '/':
			if(s->size >= 2)
				s->arr[s->size-2] /= back(s);
			pop(s);
			break;
		case 'j':
			if(s->size >= 2)
				s->arr[s->size-2] = pow(s->arr[s->size-2], s->arr[s->size-1]);
			pop(s);
			break;
		case 'e':
			if(!strcmp("exit", argv[i])) {
				list_stack(s);
				goto exit;
			}
			break;
		default:
			fprintf(stderr, "Invalid operation!\n Unknown '%c'", argv[i][0]);
			break;
		}
		exit: ;
	}
	list_stack(s);
	destroy_stack(s);

	return 0;
}