#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
} 

// Function to insert a node at the end of the linked list
void insetAtEnd(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the linked list
void displayList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int n, data;

    printf("Enter number of elements you want to add: ");
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        printf("Enter data for node-%d: ", i);
        scanf("%d", &data);
        insetAtEnd(&head, data);
    }

    printf("Linked List: ");
    displayList(head);

    return 0;
}