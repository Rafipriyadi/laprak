#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // Mengubah MAX_STACK_SIZE menjadi 100

typedef struct Stack {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void createEmptyStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1; // Mengubah dari = menjadi ==
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack Penuh\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = value;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong\n");
        return '\0';
    }
    char value = stack->data[stack->top];
    stack->top--;
    return value;
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nStack kosong\n");
        return;
    }
    printf("\nStack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%c ", stack->data[i]);
    }
    printf("\n");
}

int Matching(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

char *isBalanced(char *expression) {
    Stack stack;
    createEmptyStack(&stack);
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(&stack)) {
                return "NO";
            } else if (!Matching(pop(&stack), expression[i])) {
                return "NO";
            }
        }
        i++;
    }

    if (isEmpty(&stack))
        return "YES";
    else
        return "NO";
}

int main() {
    char expression[100];
    printf("Masukkan urutan tanda kurung: ");
    scanf("%s", expression);

    printf("%s\n", isBalanced(expression));

    return 0;
}