//Doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

//crete node
struct Node* createNode(int data){
	struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
	nn -> data = data;
	nn -> prev = NULL;
	nn -> next = NULL;
	return nn;
}

//Trvaerse
//forward-traversal
void forwardTraversal(struct Node* head){
	struct Node* curr = head;
	while(curr != NULL){
		printf("%d ", curr -> data);
		curr = curr -> next;
	}
	printf("\n");
}

//backward traversal
void backwardTraversal(struct Node* tail){
	struct Node* curr = tail;
	
	while(curr != NULL){
		printf("%d ", curr -> data);
		
		curr = curr -> prev;
	}
}

//length
int findSize(struct Node* curr) {
  int size = 0;
  while (curr != NULL) {
    size++;
    curr = curr->next;
  }
  return size;
}

//insertion at begin
struct Node* insertBegin(struct Node* head, int data){
	struct Node* nn = createNode(data);
	nn -> prev = NULL;
	nn -> next = head;
	head -> prev = nn;
	return nn;
}

//insertion at end
struct Node* insertEnd(struct Node *head, int new_data) {
    struct Node *new_node = createNode(new_data);

    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = new_node;
        new_node->prev = curr;
    }

    return head;
}



int main() {
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Forward Traversal: ");
    forwardTraversal(head);
    
    printf("Backward Traversal: ");
    backwardTraversal(third);
    
    int data = 1;
    head = insertAtFront(head, data);
    head = insertEnd(head, 4);

    return 0;
}
