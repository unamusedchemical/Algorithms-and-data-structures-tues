#include "hash.h"
#include "dyn_arr.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int hash(char *key) {
    return key[0];
}

tableV_t *init_table(int bucket_num) {
    tableV_t *new = malloc(sizeof(tableV_t));
    new->bucket_num = (unsigned) bucket_num;
    new->buckets = calloc(bucket_num, sizeof(listV_t *));
}

void put(tableV_t *table, char *key, void *value) {
    if(!table) return;
    int place = hash(key) % table->bucket_num;
    listV_t *temp = table->buckets[place];
    while(temp) {
        if(!strcmp(temp->key, key)) {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }
    listV_t *new = malloc(sizeof(listV_t));
    new->key = malloc(sizeof(char) * strlen(key));
    strcpy(new->key, key);
    new->value = value;
    new->next = table->buckets[place];
    table->buckets[place] = new;
}

void *get(tableV_t *table, char *key) {
    if(!table) return NULL;
    int place = hash(key) % table->bucket_num;
    listV_t *temp = table->buckets[place];
    while(temp) {
        if(!strcmp(temp->key, key)) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

int contains(tableV_t *table, char *key) {
    if(!table) return false;
    int place = hash(key) % table->bucket_num;
    listV_t *temp = table->buckets[place];
    while(temp) {
        if(!strcmp(temp->key, key)) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void create_var(stack_t *s, tableV_t *table, char *buf) {
    if(s->size >= 1) {
        char *key = buf + 1;
        if(contains(table, key)) {
            printf("Variable already declared!\n");   
            return;
        }
        put(table, key, &s->arr[s->size-1]);
        pop(s);
    }    
}

void check_var(stack_t *s, tableV_t *table, char *buf) {
    double *a = get(table, buf);
    if(contains(table, buf))
        push_back(s, *a);
}