#ifndef HASH
#define HASH

#include <stddef.h>
#include "dyn_arr.h"
#define KEY_LEN 256

typedef struct list_vals {
    struct list_vals *next;
    void *value;
    char *key;
} listV_t;

typedef struct table_vals {
    size_t bucket_num;
    listV_t **buckets;
} tableV_t;

int hash(char *key);
tableV_t *init_table(int bucket_num);
void put(tableV_t *table, char *key, void *val);
void *get(tableV_t *table, char *key);
int contains(tableV_t *table, char *key);
void create_var(stack_t *s, tableV_t *table, char *buf);
void check_var(stack_t *s, tableV_t *table, char *buf);

#endif