#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 2
#define STEP 3

typedef struct node{
	int key;
	int val;
	struct node **forward;

}node_t;

typedef struct skiplist{
	node_t *head;
	unsigned long size;
}list_t;

list_t init_list(list_t list){
	node_t *head = malloc(sizeof(node_t));
	list.head = head;
	list.size = 0;
	head->forward = (node_t **)calloc(sizeof(node_t *), MAX_LEVEL);	
	head->key = -1;

	return list;
}

node_t *list_search(list_t list, int key){
	node_t *current = list.head;
	
	for(int i = MAX_LEVEL-1; i >= 0; --i){
		while(current->forward[i] && current->forward[i]->key <= key){
			current = current->forward[i];
		}
	}

	if(current->key == key){
		printf("Node with key %d is present in the list\n", key);
	}else{
		printf("Node with key %d is NOT present in the list\n", key);
	}

	return current;	
}

void insert_replace(list_t *list, unsigned int key, int val){
	node_t **update = (node_t **)malloc(sizeof(node_t *) * MAX_LEVEL); 	
	node_t *current = list->head;
	
	for(int i = MAX_LEVEL-1; i >= 0; --i){
		while(current->forward[i] && current->forward[i]->key < key){
			current = current->forward[i];
		}
		update[i] = current;
	}
	
	node_t *next = current->forward[0];

	if(next && next->key == key){
		next->val = val;
	}

	node_t *new = malloc(sizeof(node_t));
	new->key = key;
	new->val = val;
	int level = (key % 3) ? 1 : 2;
	new->forward = (node_t **)malloc(sizeof(node_t *) * level);
 	
	for(int i = 0; i < level; ++i){
		new->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = new;
	}	
	free(update);
	list->size++;
}

void pop_node(list_t *list, unsigned int key){
	/*void pop_node(list_t *list, unsigned int key){
		node_t *delete = list_search(*list, key);
		
		if(!delete){
			printf("Element with key %d not found", key);
			return;
		}
		
		node_t *current = list->head;
		
		for(int i = sizeof(delete->forward)/sizeof(node_t *) - 1; i >= 0; --i){
			while(current->forward[i] && current->forward[i]->key < delete->key){
				current = current->forward[i];
			}
			
			current->forward[i] = (current->forward[i]) ? current->forward[i]->forward[i] : NULL;
		}
		
		free(delete);

	}*/
	node_t *delete = list_search(*list, key);
	
	if(!delete){
		printf("Element with key %d not found", key);
		return;
	}
	
	node_t **update = (node_t **)malloc(sizeof(node_t *) * MAX_LEVEL); 	
	node_t *current = list->head;
	
	for(int i = MAX_LEVEL-1; i >= 0; --i){
		while(current->forward[i] && current->forward[i]->key < key){
			current = current->forward[i];
		}
		update[i] = current;
	}
	
	current = current->forward[0];
	
	for(int i = sizeof(delete->forward)/sizeof(node_t *) - 1; i >= 0; --i){
		update[i]->forward[i] = current->forward[i];
	}
	
	free(delete);
	list->size++;
}

void destroy(list_t *list){
	node_t *current;
	
	while(list->head != NULL){
		current = list->head;
		list->head = current->forward[0];
		free(current);
	}
}

void print_list(list_t *list){
	int level = MAX_LEVEL;
	node_t *current = list->head;
	
	for(int i = MAX_LEVEL-1; i >= 0; --i){
		printf("level %d: ", i);
		if(current->forward[i]){
			do{
				printf("key=>%d:val=>%d; ", current->forward[i]->key, current->forward[i]->val);
				current = current->forward[i];
			}while(current->forward[i]);
		}else{
			printf("NONE");	
		}

		printf("\n");
		current = list->head;
	}
}



int main(){	
	list_t list = init_list(list);
	insert_replace(&list, 1, 5);
	insert_replace(&list, 3, 77);
	pop_node(&list, 1);
	list_search(list, 1);
	print_list(&list);
	destroy(&list);
	
	return 0;
}
