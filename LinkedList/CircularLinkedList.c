//circular linked list

#include <stdio.h>
#include <stdlib.h>

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

void printList(struct Node* last){
	if(last == NULL){
		return;
	}
	struct Node* head = last -> next;
	while(1){
		printf("%d ", head->data);
		head = head -> next;
		if(head == last -> next){
			break;
		}
	}
	printf("\n");
}

//Insertion in an empty list
struct Node* insertEmptyList(struct Node* last, int data){
	if(last != NULL){
		return last;
	}
	
	struct Node* nn = createNode(data);
	
	last = nn;
	return last;
}

//insert at beginning
struct Node* insertAtBegin(struct Node* last, int data){
	struct Node* nn = createNode(data);
	
	if(last == NULL){
		nn -> next = nn;
		return nn;
	}
	
	nn -> next = last -> next ;
	last -> next = nn;
	return last;
}

//insert at end
struct Node* insertAtEnd(struct Node* tail, int data){
	struct Node* nn = createNode(data);
	if(tail == NULL){
		tail = nn;
		nn -> next = nn;
	} else{
		nn -> next = tail -> next;
		tail -> next = nn;
		tail = nn;
	}
	return tail;
}

struct Node* insertAtPos(struct Node* last, int data, int pos){
	if(last == NULL){
		if(pos != 1){
			printf("Invalid Position \n");
			return last;
		}
		struct Node* nn = createNode(data);
		last = nn;
		last -> next = last;
		return last;
	}
	
	struct Node* nn = createNode(data);
	
	struct Node* curr = last -> next;
	
	if(pos == 1){
		nn -> next = curr;
		last -> next = nn;
		return last;
	}
	
	for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;

        // If position is out of bounds
        if (curr == last->next) {
            printf("Invalid position!\n");
            return last;
        }
    }
    
    nn -> next = curr -> next;
    curr -> next = nn;
    
    if(curr == last){
    	last = nn;
	}
	return last;
}

//delete the 1st node
struct Node* deleteFirstNode(struct Node* last){
	if(last == NULL){
		printf("List is empty \n");
		return NULL;
	}
	
	struct Node* head = last -> next;
	
	if(head == last){
		free(head);
		last = NULL;
	} else{
		last -> next = head -> next;
		free(head);
	}
	return last;
}

//delete at specific pos
struct Node* deleteSpecificNode(struct Node* last, int key){
	if(last == NULL){
		printf("list ie empty");
		return NULL;
	}
	
	struct Node* curr = last -> next;
	struct Node* prev = last;
	
	if(curr == last && curr -> data == key){
		free(curr);
		last = NULL;
		return last;
	}
	// If the node to be deleted is the first node
    if (curr->data == key) {
        last->next = curr->next;
        free(curr);
        return last;
    }
    
    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        free(curr);
    } else {
        // If the node to be deleted is not found
        printf("Node with data %d not found.\n", key);
    }

    return last;
}

//delete at end
struct Node* deleteLastNode(struct Node* last) {
    if (last == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    struct Node* head = last->next;

    if (head == last) {
        free(last);
        last = NULL;
        return last;
    }

    struct Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }

    curr->next = head;
    free(last);
    last = curr;

    return last;
}

//search a key
void searchKey(struct Node* last, int key) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* head = last->next;
    struct Node* temp = head;

    do {
        if (temp->data == key) {
            printf("Found\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Not found\n");
}



int main(){
	struct Node *first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);
    struct Node *last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);

    last = insertAtBegin(last, 5);

    printf("List after inserting 5 at the beginning: ");
    printList(last);
    
    last = insertAtEnd(last, 6);

    printf("List after inserting 6: ");
    printList(last);
    
    int data = 5, pos = 2;
    last = insertAtPos(last, data, pos);
    printf("List after insertions: ");
    printList(last);
    
    last = deleteFirstNode(last);
    printf("List after deleting first node: ");
    printList(last);
    
    int key = 3;
    last = deleteSpecificNode(last, key);
    printf("List after deleting node %d: ", key);
    printList(last);
    
    searchKey(last, 4);

	return 0;
}
