#include <stdio.h>
#include <stdlib.h>
#include <limit.h>
//Infix to postfix

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

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

char* Infix_Postfix(char exp[MAX]){
	struct stack* s = (struct stack)malloc(sizeof(struct stack));
	s -> top = -1;
	char* res = (char*)malloc((strlen(exp)+1)*sizeof(char));
	int resIndex = 0;
	
	for(int i = 0; exp[i] != '\0'; i++){
		char c = exp[i];
		
		if(c == '') continue;
		
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
			res[resIndex++] = c;
		}
		else if(c == '('){
			push(s, c);
		}
		
		else if(c == ')'){
			while(s->top != -1 && peek(s) != '('){
				res[resIndex++] = pop(s);
			}
			if(s -> top != -1){
				pop(s);
			}
		}
		
		else if(isOperator(c)){
			while(s -> top != -1 && precedence(peek(s)) >= precedence(c) && peek(s) != '('){
				res[resIndex++] = pop(s);
			} 
			push(s, c);
		}
	}
	
	while(s -> top != -1){
		res[resIndex++] = pop(s);
	}
	
	res[resIndex] = '\0';
	free(s);
	return res;
}
