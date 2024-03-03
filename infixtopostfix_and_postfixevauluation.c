#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack {
    int top;
    char items[MAX_SIZE];
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element %c\n", value);
    } else {
        stack->items[++stack->top] = value;
    }
}
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return '\0'; // Return a sentinel value to indicate an error
    } else {
        return stack->items[stack->top--];
    }
}
int getPrecedence(char operator) {
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
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char currentSymbol = infix[i];

        if (isalnum(currentSymbol)) {
            postfix[j++] = currentSymbol;
        } else if (currentSymbol == '(') {
            push(&stack, currentSymbol);
        } else if (currentSymbol == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) >= getPrecedence(currentSymbol)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, currentSymbol);
        }

        i++;
    }
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        char currentSymbol = postfix[i];

        if (isalnum(currentSymbol)) {
            push(&stack, currentSymbol - '0'); // Convert char to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (currentSymbol) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                case '^':
                    push(&stack, operand1 ^ operand2);
                    break;
                default:
                    printf("Invalid operator in postfix expression\n");
                    return -1;
            }
        }
        i++;
    }
    return pop(&stack);
}
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result of the postfix expression: %d\n", result);
    }
    return 0;
}
