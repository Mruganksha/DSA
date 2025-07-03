//valid parenthesis

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int top;
	int capacity;
	char *a;	
};

struct Stack* createstack(int capacity){
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s -> capacity = capacity;
	s -> top = -1;
	s -> a = (char*)malloc(capacity * sizeof(char));
	return s;
}

int isFull(struct Stack* s){
	return s -> top >= s -> capacity -1;
}

int isEmpty(struct Stack* s){
	return s -> top < 0;
}

int push(struct Stack* s, int x){
	if(isFull(s)){
		printf("stack is full\n");
		return 0;
	}
	s -> a[++s->top] = x;
	return 1;
}

int pop(struct Stack* s){
	if(isEmpty(s)){
		printf("stack is empty\n");
		return 0;
	}
	return s->a[s->top--];
}

bool isMatchingPair(char open, char close){
	return (open == '(' && close == ')') ||
	    (open == '[' && close == ']') ||
	    (open == '{' && close == '}');
}

bool isBalanced(char str[]){
	int len = strlen(str);
	struct Stack* s = createstack(len);
	
	for(int i = 0; i < len; i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			push(s, str[i]);
		}
		else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
		     if(isEmpty(s)){
		     	return false;
			 }
			 char topChar = pop(s);
			 if(!isMatchingPair(topChar, str[i])){
			 	return false;
			 }
		}
	}
	
	bool balanced = isEmpty(s);
	free(s->a);
	free(s);
	return balanced;
}

int main() {
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("Valid Parentheses\n");
    } else {
        printf("Invalid Parentheses\n");
    }
    return 0;
}
