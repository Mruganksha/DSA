//Stack 
//FILO

//Stack using array
#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	int capacity;
	int *a;
};

struct stack* createStack(int capacity){
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s -> capacity = capacity;
	s -> top = -1;
	s -> a = (int*)malloc(capacity * sizeof(int));
	return s;
}

int isFull(struct stack* s){
	return s -> top >= s -> capacity -1;
}

int isEmpty(struct stack* s){
	return s -> top < 0;
}

int push(struct stack* s, int x){
	if(isFull(s)){
		printf("stack is full\n");
		return 0;
	}
	s -> a[++s->top] = x;
	return 1;
}

int pop(struct stack* s){
	if(isEmpty(s)){
		printf("stack is empty\n");
		return 0;
	}
	return s->a[s->top--];
}

int peek(struct stack* s){
	if(isEmpty(s)){
		printf("stack is empty \n");
		return 0;
	}
	return s->a[s->top];
}


int main() {
    struct Stack* s = createStack(5);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("%d popped from stack\n", pop(s));

    printf("Top element is: %d\n", peek(s));

    printf("Elements present in stack: ");
    while (!isEmpty(s)) {
        printf("%d ", peek(s));
        pop(s);
    }

    return 0;
}
