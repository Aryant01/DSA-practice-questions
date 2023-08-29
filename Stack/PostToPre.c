// !INCOMPLETE!

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 100

int isOperator(char x) {
    switch(x) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
    }
    return 0; 
}

void postToPre(char *post_exp, char *prefix_exp) {
    char s[MAX_SIZE][MAX_SIZE];
    int top = -1;

    int length = strlen(post_exp);

    for (int i=0; i < length; i++) {
        if (isOperator(post_exp[i])) {
            char op1[MAX_SIZE], op2[MAX_SIZE];
            strcpy(op1, s[top--]);
            strcpy(op2, s[top--]);

            sprintf(s[++top], "%c%s%s", post_exp[i], op2, op1);
        }

        else {
            
        }
    }
}



