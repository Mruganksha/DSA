//check if ll is palindrome
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node* next;
};

struct stack{
	int data;
	struct stack* next;
};

//Approach 1: (1st traverse whole list and put the elements in stack, then after that remove one by one elements from stack and compare it with the list from 1st if it matches return true or false
void push(struct stack** top, int data){
	struct stack* nn = (struct stack*)malloc(sizeof(struct stack));
	nn -> data = data;
	nn -> next = *top;
	*top = nn;
}

int pop(struct stack** top){
	if(*top == NULL){
		return -1;
	}
	int value = (*top) -> data;
	struct stack* temp = *top;
	*top = (*top) -> next;
	free(temp);
	return value;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
bool isPalindrome(struct Node* head){
	struct stack* s = NULL;
	struct Node* temp = head;
	
	//push all elements in stack
	while(temp != NULL){
		push(&s, temp -> data);
		remp = temp -> next;
	}
	
	//compare while popping
	temp = head;
	while(temp != NULL){
		int val = pop(&s);
		if(temp->data != val){
			return false;
		}
		temp = temp -> next;
	}
	return true;
}*/

//Approach 2: 
//find mid then we will break into 2 half then reverse 2nd half then traverse both and compare
//but for odd: 
//step1: find mid
//step 2: reverse
//step 3: compare
struct Node* reverseList(struct Node* head) {

    struct Node *curr = head, *prev = NULL, *next;

    while (curr != NULL) {

        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(struct Node* head){
	if(head == NULL || head -> next == NULL){
		return true;
	}
	struct Node* slow = head;
	struct Node* fast = head;
	
	//mid
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	
	struct Node* newHead = reverseList(slow->next);
	struct Node* first = head;
	struct Node* second = newHead;
	while(second != NULL){
		if(first->data != second->data){
			reverseList(newHead);
			return false;
		}
		first = first -> next;
		second = second -> next;
	}
	reverseList(newHead);
	return true;
}






int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}
