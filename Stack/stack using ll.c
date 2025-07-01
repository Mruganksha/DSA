#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn -> data = data;
	nn -> next = NULL;
	return nn;
}

struct Stack{
	struct Node* head;
};

void initstack(struct Stack* s){
	s->head = NULL;
}

int isEmpty(struct Stack* s){
	return s->head == NULL;
}

void push(struct Stack* s, int data){
	struct Node* nn = createNode(data);
	
	if(!nn){
		printf("\n stack overflow");
		return;
	}
	
	nn->next = s->head;
	s->head = nn;
}

void pop(struct Stack* s){
	if(isEmpty(s)){
		printf("\n stack is empty");
		return;
	}
	else{
		struct Node* temp = s -> head;
		s->head = s->head->next;
		
		free(temp);
	}
}

int peek(struct Stack* s){
	if(!isEmpty(s)){
		return s->head->data;
	} else{
		printf("\n stack is empty");
		return INT_MIN;
	}
}

int main() {
  
    struct Stack stack;
    initstack(&stack);

    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);

    printf("Top element is %d\n", peek(&stack));

  	printf("Removing two elements...\n");
    pop(&stack);
    pop(&stack);

    printf("Top element is %d\n", peek(&stack));

    return 0;
}
