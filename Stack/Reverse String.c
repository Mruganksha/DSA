//Reverse String using Stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int capacity;
    char* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '\0'; 
}

void reverse(char str[]) {
    int n = strlen(str);
    struct Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }

    for (int i = 0; i < n; i++) {
        str[i] = pop(stack);
    }

    free(stack->array);
    free(stack);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    reverse(str);
    printf("Reversed string: %s\n", str);

    return 0;
}



