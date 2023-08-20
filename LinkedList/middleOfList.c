// Program to find middle element of a linked list

#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node* next;
};
typedef struct node node;

// allocate a memory location for new node
node* createNewNode(int value) {
    node* newNode; 
    newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node after the last node added
node addNodeAfter(node** head, int data) {
    node* newNode = createNewNode(data);

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

// Function to print the list
void printList(node *head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL");
}

// Function to find the middle element of the list
int middleNode(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next; // When fast pointer will reach the last element, slow pointer will be pointing to the middle element
    } 
    return slow->value;      
}

// Driving function
int main(){
    int n, value;
    printf("Enter number of node: ");
    scanf("%d", &n);

    node* head = NULL;

    for (int i=1; i <= n; i++) {
        printf("Enter value of node-%d: ", i);
        scanf("%d", &value);
        addNodeAfter(&head, value);
    }

    printf("\nLINKED LIST: \n");
    printList(head);

    //int mid = middleNode(&head);

    printf("\nMiddle Node: %d\n", middleNode(head));

    return 0;
}