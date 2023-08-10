#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// function to check if character is operator or not
int isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return 1;
    }
    return 0;
}

// Convert prefix to Postfix expression
char *preToPost(char *pre_exp) {
    char *post_exp = (char *)malloc(MAX_SIZE * sizeof(char));
    int length = strlen(pre_exp);

    // Initialize stack
    char stack[MAX_SIZE][MAX_SIZE];
    int top = -1;

    // Reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Check if symbol is operator
        if (isOperator(pre_exp[i])) {
            // Pop two operands from stack
            char op1[MAX_SIZE];
            strcpy(op1, stack[top]);
            top--;

            char op2[MAX_SIZE];
            strcpy(op2, stack[top]);
            top--;

            // Concatenate the operands and operator
            char temp[MAX_SIZE * 2];
            sprintf(temp, "%s%s%c", op1, op2, pre_exp[i]);

            // Push string temp back to stack
            strcpy(stack[++top], temp);
        } else {
            // Symbol is an operand, push it to the stack
            char operand[2];
            operand[0] = pre_exp[i];
            operand[1] = '\0';
            strcpy(stack[++top], operand);
        }
    }

    // Stack contains only the Postfix expression
    strcpy(post_exp, stack[top]);
    return post_exp;
}

int main() {
    char pre_exp[] = "*+AB-CD";
    char *post_exp = preToPost(pre_exp);
    printf("Postfix : %s\n", post_exp);
    free(post_exp);
    return 0;
}
//AB+CD-*