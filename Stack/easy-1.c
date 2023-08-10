// Convert Infix expression to Postfix expression

/*Infix expression: The expression of the form “a operator b” (a + b) i.e., when an operator is in-between every pair of operands.
Postfix expression: The expression of the form “a b operator” (ab+) i.e., When every pair of operands is followed by an operator.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

// Function to return precedence of operators
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default: 
            return -1;
    }
}

// Function to check if the scanned character is a operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'); 
}

// Function to convert infix expression to postfix expression
char* infixToPostfix(char* infix) {
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 2) * sizeof(char));
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') continue;

        // If the scanned char is operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        //if the scanned char is '(' push it in the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }

        // if the scanned char is ')' 
        // pop the stack and add it to the 
        //output string untill empty or '(' found 
        else if (infix[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top > -1 && stack[top] != '(')
                return "Invalid Expression";
            else 
                top--;
        }

        // If the scanned char is an operator push it in the stack
        else if (isOperator(infix[i])) {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = infix[top--];
            stack[++top] = infix[i];
        }
    }

    // Pop all the remaining elements from the stack
    while (top > -1) { 
        if (stack[top] == '(') {
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    return postfix;
}

// Driver code
int main() {
    char infix[MAX_SIZE] = "A+B*C+D";

    // Function call 
    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);

    return 0;
}