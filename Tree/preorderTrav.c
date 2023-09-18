// Preorder Traversal

#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* newNode(int data) {
    node* node = malloc(sizeof(node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void printPreorder(node* node) {
    if (node == NULL) 
        return;
    
    // First print data of the node
    printf("%d ", node->data);

    // Then recur on left subtree
    printPreorder(node->left);
    
    // Now recur on right subtree
    printPreorder(node->right);
}

int main() {
    node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder treaversal of binary tree is \n");
    printPreorder(root);

    getchar();
    return 0;
}