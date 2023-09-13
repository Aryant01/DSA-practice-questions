// Simple circular array implementation

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

struct ArrayQueue {
    int front, rear;
    int capacity;
    int *array;
};

struct ArrayQueue *Queue(int size) {
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));

    if(!Q) 
        return NULL;

    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));

    if(!Q->array) 
        return NULL;

    return Q;
}

int isEmptyQueue(struct ArrayQueue *Q) {
    //if the condition is true then 1 is returned else 0 is returned
    return (Q->front == -1);
}

int isFullQueue(struct ArrayQueue *Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int QueueSize(struct ArrayQueue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void EnQueue(struct ArrayQueue *Q, int data) {
    if (isFullQueue(Q))
        printf("Queue Overflow");
    else {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = data;

        if(Q->front == -1)
            Q->front = Q->rear;
    }
}

int DeQueue(struct ArrayQueue *Q) {
    int data = 0; //or element which does not exist in Queue
    if(isEmptyQueue(Q))  {
        printf("Queue is Empty");
        return QUEUE_EMPTY;
    }
    else {
        data = Q->array[Q->front];
        if (Q->front == Q->rear) 
            Q->front = Q->rear = -1;
        else Q->front = (Q->front + 1) % Q->capacity;
    }
    return data;
}

void DeleteQueue(struct ArrayQueue *Q) {
    if (Q) {
        if (Q->array) 
            free(Q->array);
        free(Q);
    }
}

void displayQueue (struct ArrayQueue *Q) {
    int t;
    while ((t = DeQueue(Q)) != QUEUE_EMPTY) {
        printf("%d - ", t);
    }
}

int main() {
    struct ArrayQueue *q1, *q2, *q3;

    q1 = Queue(5);
    q2 = Queue(3); 
    q3 = Queue(6);

    EnQueue(q1, 23);
    EnQueue(q1, 24);
    EnQueue(q1, 25);
    EnQueue(q1, 26);
    EnQueue(q1, 27);

    EnQueue(q2, 2);
    EnQueue(q2, 3);
    EnQueue(q2, 4);

    EnQueue(q3, 12);
    EnQueue(q3, 14);
    EnQueue(q3, 15);
    EnQueue(q3, 16);
    EnQueue(q3, 17);
    EnQueue(q3, 18);

    displayQueue(q3);

    DeleteQueue(q1);
    DeleteQueue(q2);
    DeleteQueue(q3);
}