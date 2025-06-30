//find miidle of linked list

#include <stdio.h>
#include <stdlib.h>

//for odd no issue
//for even we take 2nd like if n is 6 then middle will be 4th term
//(n/2) + 1

//Approach 1:
struct Node{
	int data;
	struct Node* next;
};

struct Node* findMiddle(struct Node* head){
	struct Node* temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	int mid = (count/2) + 1;
	temp = head;
	while(temp != NULL){
		mid = mid - 1;
		if(mid == 0){
			break;
		}
		temp = temp -> next;
	}
	return temp;
} //here TC: O(N) + O(N/2) 

//optimal approach will be : tortoise and hare approach
//slow and fast pointer
//when fast reaches last slow will point to mid
//in case of even: fast reaches last node
//in case of odd: fast will reach null

struct Node* findMid(struct Node* head){
	struct Node* slow = head;
	struct Node* fast = head;
	while(fast != NULL && fast -> next != NULL){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}

