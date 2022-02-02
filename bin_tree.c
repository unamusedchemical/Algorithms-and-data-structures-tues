#include <stdio.h>
#include <stdlib.h>

#define DIF 1

struct tree {
    int val;
    struct tree *left;
    struct tree *right;
};

typedef struct tree node_t;

node_t *add(node_t *root, int val) {
    if(!root) {
        node_t *new = malloc(sizeof(node_t));
        new->val = val;
        new->right = NULL;
        new->left = NULL;

        return new;
    }

    if(val < root->val) {
        root->left = add(root->left, val);
    } else if(val > root->val) {
        root->right = add(root->right, val);
    }

    return root;
}

int find(node_t *root, int val) {
    if(!root)
        return 0;
    if(root->val == val)
        return 1;

    if(val > root->val)
        return find(root->right, val);
    else if(val < root->val)
        return find(root->left, val);
}

node_t *findRightest(node_t *root) {
    if(!root || !root->right) {
        return root;
    }
    return findRightest(root->right);
}

node_t *findLeftest(node_t *root) {
    if(!root || !root->left) {
        return root;
    }
    return findLeftest(root->left);
}

node_t *delete(node_t *root, int val) {
    if(!root)
        return NULL;

    if(val > root->val) {
        root->right = delete(root->right, val);
    } else if(val < root->val) {
        root->left = delete(root->left, val);
    } else {
        if(root->right) {
            node_t *newRoot = root->right;
            //findRightest of root->left and add temp->left to the end
            node_t *temp = findRightest(root->left);
            if(temp)
                temp->right = newRoot->left;
            newRoot->left = root->left;
            free(root);
            return newRoot;
        } else {
            node_t *temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
}

void _display(node_t *root, int spaces) {
    if(!root) return;
    _display(root->right, spaces+10);

    for(int i = 0; i < spaces; ++i) {
        printf(" ");
    }
    printf("%d\n", root->val);

    _display(root->left, spaces+10);
}

void display(node_t *root) {
    printf("RIGHT\n\n");
    _display(root, 0);
    printf("\nLEFT\n");
}

void preOrderTraversal(node_t *root) {
    if(!root) return;
    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node_t *root) {
    if(!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->val);
}

void inOrderTraversal(node_t *root) {
    if(!root) return;
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

void freeTree(node_t *root) {
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
//inefficient way
//int _isBST(node_t *root) {
//    if(!root) return 1;
//
//    node_t *leftMax = findRightest(root->left);
//    node_t *rightMin = findLeftest(root->right);
//
//    if(leftMax && root->val < leftMax->val) return 0;
//    if(rightMin && root->val > rightMin->val) return 0;
//
//    return _isBST(root->left) && _isBST(root->right);
//}


//efficient way but uncool
//we use in order traversal
//int _isBST(node_t *root, node_t **prev) {
//    if(!root) return 1;
//
//    if(!_isBST(root->left, prev)) {
//        return 0;
//    }
//
//    if((*prev) && root->val <= (*prev)->val) {
//        return 0;
//    }
//
//    *prev = root;
//
//    return _isBST(root->right, prev);
//}

//efficient and cool way
//we define a range for every node in the BST
int _isBST(node_t *root, int min, int max) {
    if(!root) return 1;

    if(root->val <= min || root->val >= max) {
        return 0;
    }

    return _isBST(root->left, min, root->val)
           && _isBST(root->right, root->val, max);
}

int isBST(node_t *root) {
//    node_t *prev = NULL;
//    return _isBST(root, &prev);
    return _isBST(root, INT_MIN, INT_MAX);
}

int height(node_t *root) {
    if(!root) {
        return -1;
    }

    int left = height(root->left) + 1;
    int right = height(root->right) + 1;

    return left > right ? left : right;
}

//complicated way
//if there is a height difference that is more than 1 between
// the left and right subtrees then the tree is unbalanced
int isBalanced(node_t *root) {
    if(!root) {
        return 1;
    }

    if(abs(height(root->left) - height(root->right)) > 1) {
        return 0;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    node_t *root = add(NULL, 12);
    add(root, 123);
    add(root, 122);
    add(root, 125);
    add(root, 10);
    add(root, 11);
    add(root, 9);
    delete(root, 123);

    display(root);
    printf("%d", isBST(root));
    freeTree(root);

    return 0;
}
