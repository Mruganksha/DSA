//sort a ll of 0's 1's and 2's

//approach 1: count 0s, 1s, 2s by traversing, then do other traversal and replace elements by count

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* sortOrder(struct Node* head){
	int countZero = 0;
	int countOne = 0;
	int countTwo = 0;
	struct Node* temp = head;
	while(temp != NULL){
		if(temp->data == 0){
			countZero++;
		}
		if(temp->data == 1){
			countOne++;
		}
		if(temp->data == 2){
			countTwo++;
		}
		temp = temp->next;
	}
	temp = head;
	while(countZero--){
		temp->data = 0;
		temp = temp -> next;
	}
	while (countOne--) {
        temp->data = 1;
        temp = temp->next;
    }
    while (countTwo--) {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
} //not optimized as TC: O(2N)

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Approach 2: by chnging links
struct Node* sortList(struct Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	// Dummy heads and tails for 0s, 1s, and 2s lists
    struct Node *zeroD = NULL, *oneD = NULL, *twoD = NULL;
    struct Node *zero = NULL, *one = NULL, *two = NULL;

    struct Node* curr = head;

    while (curr) {
        struct Node* next = curr->next;
        curr->next = NULL;

        if (curr->data == 0) {
            if (!zeroD) zeroD = zero = curr;
            else {
                zero->next = curr;
                zero = zero->next;
            }
        } else if (curr->data == 1) {
            if (!oneD) oneD = one = curr;
            else {
                one->next = curr;
                one = one->next;
            }
        } else {
            if (!twoD) twoD = two = curr;
            else {
                two->next = curr;
                two = two->next;
            }
        }
        curr = next;
    }

    // Reconnect the lists: 0s -> 1s -> 2s
    if (zero) zero->next = oneD ? oneD : twoD;
    if (one) one->next = twoD;

    // New head
    if (zeroD) return zeroD;
    else if (oneD) return oneD;
    else return twoD;
}



int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);

    printf("Original list: ");
    printList(head);

    head = sortOrder(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}

