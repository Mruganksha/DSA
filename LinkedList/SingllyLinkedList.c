#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node* next;
};

//create new node
struct Node* createNode(int data){
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn -> data = data;
	nn -> next = NULL;
	return nn;
}

//traverse
void Traverse(struct Node* head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head -> next;
	}
	printf("\n");
}

//search
bool searchKey(struct Node* head, int data){
	struct Node* curr = head;
	while(curr != NULL){
		if(curr -> data == data){
			return true;
		}
		curr = curr -> next;
	}
	return false;
}

//length od singly ll
int length(struct Node* head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head -> next;
	}
	return count;
}

//INSERTION OF SINGLY LINKED-LIST
//at begining
struct Node* InsertionAtFront(struct Node* head, int data){
	struct Node* nn = createNode(data);
	
    nn -> next = head;
    return nn;
}

//at end
struct Node* InsertAtEnd(struct Node* head, int data){
	struct Node* nn = createNode(data);
	
	if(head == NULL){
		return nn;
	}
	
	struct Node* last = head;
	while(last -> next != NULL){
		last = last -> next;
	}
	
	last -> next = nn;
	return head;
}

//insertion at specific position
struct Node* insertPos(struct Node* head, int pos, int data){
	if(pos < 1){
		return head;
	}
	
	if(pos == 1){
		struct Node* nn = createNode(data);
		nn -> next = head;
		return nn;
	}
	
	struct Node* curr = head;
	
	//traverse to node that will be present just before nn
	for(int i = 1; i < pos - 1 && curr != NULL; i++){
		curr = curr -> next;
	}
	
	//if pos is greater than no of nodes
	if(curr == NULL){
		return head;
	}
	
	struct Node* nn = createNode(data);
	
	nn -> next = curr -> next;
	curr -> next = nn;
	
	return head;
}

//deletion
//at begining
struct Node* deleteHead(struct Node* head){
	if(head == NULL){
		return NULL;
	}
	
	//store current head in a temp variable
	struct Node* temp = head;
	
	head = head -> next;
	free(temp);
	return head;
}

//at end
struct Node* deleteEnd(struct Node* head){
	//if list is empty , return null
	if(head == NULL){
		return NULL;
	}
	
	//if only 1 node
	if(head -> next == NULL){
		free(head);
		return NULL;
	}
	
	//find second last node
	struct Node* second_last = head;
	while(second_last -> next -> next != NULL){
		second_last = second_last -> next;
	}
	
	//delete last
	free(second_last -> next);
	
	second_last -> next = NULL;
	return head;
}

struct Node* deleteNode(struct Node* head, int pos){
	struct Node* temp = head;
	struct Node* prev = NULL;
	
	if(temp == NULL){
		return head;
	}
	
	if(pos == 1){
		head = temp -> next;
		free(temp);
		return head;
	}
	
	for(int i = 1; temp != NULL && i < pos; i++){
		prev = temp;
		temp = temp -> next;
	}
	
	if(temp != NULL){
		prev -> next = temp -> next;
		free(temp);
	}else{
		printf("Data not present\n");
	}
	return head;
}

int main(){
	struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    
    Traverse(head);
    
    if(searchKey(head, 30)){
    	printf("yes");
	}else{
		printf("No");
	}
	
	int count = length(head);
	printf("\ncount: %d ", count);
	
	int data = 50;
	head = InsertionAtFront(head, data);
	head = InsertAtEnd(head, data);
	head = insertPos(head, 3, data);
	printf("\nModified List: ");
    Traverse(head);
    
    head = deleteHead(head);
    head = deleteEnd(head);
    head = deleteNode(head, 2);
    printf("\nModified List after deletion: ");
    Traverse(head);
    
    return 0;
}
