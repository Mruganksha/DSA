//add 1 to a ll

//like if ll : 1->5->9 then output will be head: 160
//9->9->9 then add a node as head and return 1000

#include <stdio.h>
#include <stdlib.h>

//Approach 1: reverse list 951 then as we want to add 1 keep carry as 1 then do 9 + 1 = 10 , 10 so again carry will be 1 now, 5 + 1 = 6 no carry now take one as it is so ans is 160
//now for 9999 even when temp reaches NULL, there is a carry left so again reverse and add a new node at begining pointing as head
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

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

struct Node* add(struct Node* list){
	head = reverseList(head);
	struct Node* temp = head;
	int carry = 1;
	while(temp != NULL){
		temp->data = temp->data + carry;
		if(temp->data < 10){
			carry = 0;
			break;
		}
		else{
			temp->data = 0;
			carry = 1;
		}
		temp = temp ->next;
	}
	if(carry == 1){
		struct Node* nn = createNode(1);
		head = reverse(head);
		nn -> next = head;
		return nn;
	}
	head = reverse(head);
	return head;
} //TC: O(3N)

//Approach 2:
//recursion backtracking
int addOneUtil(struct Node* head) {
    if (head == NULL)
        return 1;  

    int carry = addOneUtil(head->next);

    int sum = head->data + carry;
    head->data = sum % 10;

    return sum / 10;  //carry
}


struct Node* addOne(struct Node* head) {
    int carry = addOneUtil(head);

    if (carry) {
        struct Node* newNode = createNode(carry);
        newNode->next = head;
        head = newNode;
    }

    return head;
}



