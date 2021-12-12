#include <stdio.h>
#include <stdlib.h>

typedef struct bTree {
    int val;
    struct bTree *left;
    struct bTree *right;
} node_t;

node_t *addNode(node_t *root, int val) {
    if (!root) {
        node_t *new = malloc(sizeof(node_t));
        new->val = val;
        new->left = NULL;
        new->right = NULL;

        return new;
    }
    if (root->val > val) {
        root->left = addNode(root->left, val);
    } else if (root->val < val) {
        root->right = addNode(root->right, val);
    }

    return root;
}

void _printTree(node_t *root, int spaces) {
    if (!root) return;
    _printTree(root->right, spaces + 10);
    printf("\n");
    for (int i = 0; i < spaces; ++i) {
        printf(" ");
    }
    printf("%d\n", root->val);
    _printTree(root->left, spaces + 10);
}

void printTree(node_t *root) {
    printf("Right\n");
    _printTree(root, 0);
    printf("\nLeft\n");
}

int _oddEvenDiff(node_t *root) {
    if(!root) return 0;
    int dif = 0;
    dif += _oddEvenDiff(root->left);
    dif += _oddEvenDiff(root->right);

    if (root->val % 2 == 0) {
//        printf("even %d\n", root->val);
        return dif + 1;
    } else {
//        printf("odd %d\n", root->val);
        return  dif - 1;
    }
}

int oddEvenDiff(node_t *root) {
    return abs(_oddEvenDiff(root));
}

int main() {
    node_t *root = addNode(NULL, 8);
    addNode(root, 3);
    addNode(root, 10);
    addNode(root, 1);
    addNode(root, 6);
    addNode(root, 4);
    addNode(root, 7);
    addNode(root, 10);
    addNode(root, 14);
    addNode(root, 13);

    printTree(root);
    printf("Difference between odd and even: %d\n", oddEvenDiff(root));

    return 0;
}
