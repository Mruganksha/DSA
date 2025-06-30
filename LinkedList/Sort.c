//sort linked list

//Approach 1: make an arr and travese the ll and add elements in arr, then apply sorting algorithm and then again replace elements of ll according to array
//not optimal way bea it takes extra )(n) space

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

int compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

struct Node* sort(struct Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	//step1. count nodes
	int count = 0;
	struct Node* temp = head;
	while(temp){
		count++;
		temp = temp -> next;
	}
	
	//step2. store values in arr
	int* arr = (int*)malloc(count * sizeof(int));
	temp = head;
	for(int i = 0; i < count; i++){
		arr[i] = temp -> data;
		temp = temp -> next;
	}
	
	//step3. sort arr
	qsort(arr, count, sizeof(int), compare);
	
	//step4. copy sorted values back to list
	temp = head;
	for(int i = 0; i < count; i++){
		temp -> data = arr[i];
		temp = temp -> next;
	}
	free(arr);
	return head;
}

//Approach2:
//apply merge sort
//tc: O(n logn), sc= O(logn)

//step1: find middle
struct Node* findMiddle(struct Node* head){
	struct Node* slow = head;
	struct Node* fast = head -> next;
	
	while(fast && fast -> next){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

struct Node* merge(struct Node* l1, struct Node* l2){
	struct Node dummy;
	struct Node* tail = &dummy;
	
	dummy.next = NULL;
	
	while(l1 && l2){
		if(l1->val < l2->val){
			tail -> next = l1;
			l1 = l1 -> next;
		} else{
			tail -> next = l2;
			l2 = l2 -> next;
		}
		tail = tail -> next;
	}
	
	tail -> next = l1 ? l1 : l2;
	return dummy.next;
}

struct Node* mergeSort(struct Node* head){
	if(head == NULL || head-> next == NULL){
		return head;
	}
	
	struct Node* mid = findMiddle(head);
	struct Node* right = mid -> next;
	mid -> next = NULL;
	
	struct Node* leftsorted = mergeSort(head);
	struct Node* rightsorted = mergeSort(right);
	
	return merge(leftsorted, rightsorted);
}

