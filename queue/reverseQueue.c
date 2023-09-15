//Program to reverse a queue using a stack

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN
#define QUEUE_EMPTY INT_MIN

typedef struct {
    int front, rear;
    int capacity;
    int *array;
} queue;

typedef struct node{
    int value;
    struct node *next;
} node;

typedef node *stack;

queue *createQueue() {
    queue *Q = malloc(sizeof(queue));

    if (!Q) return NULL;

    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(sizeof(int) * Q->capacity);
    if (!Q->array) return NULL;
    return Q;
}

int isQueueEmpty(queue *Q) {
    return (Q->front == -1);
}

int isQueueFull(queue *Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

void resizeQueue(queue *Q) {
    int size = Q->capacity;
    Q->capacity = Q->capacity * 2;
    Q->array = realloc(Q->array, sizeof(int) * Q->capacity);

    if (!Q->array) {
        printf("Memory Error!");
        return;
    }

    if (Q->front > Q->rear) {
        for (int i=0; i < Q->front; i++) {
            Q->array[i+size] = Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}
 
bool push(stack *S, int value) {
    node *newnode = malloc(sizeof(node));
    if (!newnode) return false;

    newnode->value = value;
    newnode->next = *S;
    *S = newnode;
    return true;
}

int pop(stack *S) {
    if (*S == NULL) return STACK_EMPTY;

    int result = (*S)->value;
    *S = (*S)->next;
    return result;
}

stack *createStack() {
    stack *S = malloc(sizeof(stack));
    *S = NULL;
    return S;
}

void enQueue(queue *Q, int data) {
    if (isQueueFull(Q)) resizeQueue(Q);

    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;

    if (Q->front == -1) 
        Q->front = Q->rear;
}

int deQueue(queue *Q) {
    int data = 0;

    if (isQueueEmpty(Q)) {
        printf("Queue is empty");
        return QUEUE_EMPTY;
    }
    else {
        data = Q->array[Q->front];
        if (Q->front == Q->rear) Q->front = Q->rear = -1;
        else Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}
  
void reverseQueue(queue *Q) {
    stack *S = createStack();
    while (!isQueueEmpty(Q)) 
        push(S, deQueue(Q));
    while (*S != NULL) 
        enQueue(Q, pop(S));

    free(S);
}

void printQueue(queue *Q) {
    int current = Q->front;

    while (current != -1) {
        printf(" %d-", Q->array[current]);
        if (current == Q->rear) {
            // if we've reached the end, break the loop
            break;
        }
        current = (current + 1) % Q->capacity;
    }
}

int main() {
    queue *q1;

    q1 = createQueue();
    
    enQueue(q1, 23);
    enQueue(q1, 24);
    enQueue(q1, 25);
    enQueue(q1, 26);
    enQueue(q1, 27);

    printQueue(q1);

    reverseQueue(q1);

    printf("\n");

    printQueue(q1);
}