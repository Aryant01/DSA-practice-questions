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
        case '^':
        case '%':
            return 1;
    }
    return 0;
}

// Convert prefix to Infix expression
char *preToInfix(char *pre_exp) {
    char *infix_exp = (char *)malloc(MAX_SIZE * sizeof(char));
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
            char temp[MAX_SIZE * 3];
            sprintf(temp, "(%s%c%s)", op1, pre_exp[i], op2);

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

    // Stack now contains the Infix expression
    strcpy(infix_exp, stack[top]);
    return infix_exp;
}

int main() {
    char pre_exp[] = "*+AB-CD";
    char *infix_exp = preToInfix(pre_exp);
    printf("Infix : %s\n", infix_exp);
    free(infix_exp);
    return 0;
}
//((A+B)*(C-D))