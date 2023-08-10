// Implementation of stack with Array

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define STACK_EMPTY INT_MIN
#define MAX_LENGTH 7
#define MIN (-1)

int mystack[MAX_LENGTH];

int top = MIN;

bool push(int value) {
    if (top >= MAX_LENGTH-1) return false;

    top++;
    mystack[top] = value;
}

int pop() {
    if (top == MIN) return STACK_EMPTY;

    int tmp = mystack[top];
    top--;
    return tmp;
}

int main() {

    push(23);
    push(43);
    push(53);
    push(63);
    push(73);
    push(83);
    push(93);

    int t;

    while ((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }

    return 0;
}