// Write a C program to implement a stack using an array with push and pop operations.


#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define MAX_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int stack[MAX_LENGTH];
int top = EMPTY;

bool push(int value) {
    if(top >= MAX_LENGTH-1) return false;

    top++;
    stack[top] = value;
    return true;
}

int pop() {
    if (top == EMPTY) return STACK_EMPTY;

    int result = stack[top];
    top--;
    return result;
}

int main() {
    push(23);
    push(43);
    push(21);
    push(69);
    push(01);

    int t;
    while((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }

    return 0;
}