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

void printPostorder(node* node) {
    if (node == NULL)
        return;

    // First recur on left subtree
    printPostorder(node->left);

    // Then recur on right subtree
    printPostorder(node->right);

    // Now deal with the node
    printf("%d ", node->data);
} 

int main() {
    node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    //Function call
    printf("Postorder traversal of binary tree is \n");
    printPostorder(root);

    free(root->left->left);
    free(root->left->right);

    free(root->left);
    free(root->right);

    free(root);
    
    return 0;
}