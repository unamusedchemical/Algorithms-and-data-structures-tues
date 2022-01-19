#include <stdio.h>
#include <stdlib.h>

struct tree {
    double val;
    struct tree *left;
    struct tree *right;
};

typedef struct tree node_t;

node_t *add(node_t *root, double val) {
    if(!root) {
        node_t *new = malloc(sizeof(node_t));
        new->val = val;
        new->left = NULL;
        new->right = NULL;

        return new;
    }

    if(root->val > val) 
        root->left = add(root->left, val);
    else if(root->val < val)
        root->right = add(root->right, val);

    return root;
}

int depth(node_t *root) {
    if(!root)
        return 0;

    int left = depth(root->left) + 1;
    int right = depth(root->right) + 1;

    return left > right ? left : right;
}

void getSum(node_t *root, double *sum, int level) {
    if(!root)
        return;
    
    sum[level] += root->val;

    getSum(root->left, sum, level+1);
    getSum(root->right, sum, level+1);
}

double highestSum(node_t *root) {
    
    int d = depth(root);
    double *sum = calloc(d, sizeof(double));
    double max = sum[0];

    getSum(root, sum, 0);
    
    for(int i = 1; i < d; ++i) {
        if(sum[i] > max) {
            max = sum[i];
        }
    }

    return max;
}

node_t *destroy(node_t *root) {
    if(!root) return NULL;

    root->left = destroy(root->left);
    root->right = destroy(root->right);

    free(root);
    return NULL;
}

int main() {

    node_t *root = add(NULL, 5);
    add(root, 1);
    add(root, 6);
    add(root, 4);
    add(root, -2);
    printf("\n%lf\n", highestSum(root));

    root = destroy(root);

    return 0;
}