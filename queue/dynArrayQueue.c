#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef struct DynArrayQueue {
    int front, rear;
    int capacity;
    int *array;
} queue;

queue *createDynQueue() {
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

int queueSize(queue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

void resizeQueue(queue *Q) {
    int size = Q->capacity;
    Q->capacity = Q->capacity * 2;
    Q->array = realloc(Q->array, Q->capacity);

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

void deleteQueue(queue *Q) {
    if (Q) {
        if (Q->array) free(Q->array);
        free(Q);
    }
}

void displayQueue (queue *Q) {
    int t;
    while ((t = deQueue(Q)) != QUEUE_EMPTY) {
        printf("%d - ", t);
    }
}

int main() {
    queue *q1, *q2, *q3;

    q1 = createDynQueue();
    q2 = createDynQueue(); 
    q3 = createDynQueue();

    enQueue(q1, 23);
    enQueue(q1, 24);
    enQueue(q1, 25);
    enQueue(q1, 26);
    enQueue(q1, 27);

    enQueue(q2, 2);
    enQueue(q2, 3);
    enQueue(q2, 4);

    enQueue(q3, 12);
    enQueue(q3, 14);
    enQueue(q3, 15);
    enQueue(q3, 16);
    enQueue(q3, 17);
    enQueue(q3, 18);

    displayQueue(q3);

    deleteQueue(q1);
    deleteQueue(q2);
    deleteQueue(q3);
}