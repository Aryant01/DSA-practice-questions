// Tree inorder traverssal

#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* newnode (int data) {
    node* node = malloc(sizeof(node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printInorder(node* node) {
    if (node == NULL) 
        return;

    //first recur on left child 
    printInorder(node->left);

    // Then print the data of node
    printf("%d ", node->data);

    //Now recur on right child
    printInorder(node->right);
}

int main() {
    node* root = newnode(1);

    root->left = newnode(2);
    root->right = newnode(3);

    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printf("Inorder traversal of binary tree is \n");
    printInorder(root);

    printf("\n");

    getchar();
    return 0;
}