//add 2 numbers in ll
/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* t1 = l1;
    struct ListNode* t2 = l2;
    struct ListNode* dummyNode = createNode(-1);
    struct ListNode* curr = dummyNode;
    int carry = 0;
    
    while(t1 != NULL || t2 != NULL || carry > 0){
    	int sum = carry;
    	if(t1){
    		sum = sum + t1->val;
    		t1 = t1 -> next;
		}
		if(t2){
			sum = sum + t2->val; 
			t2 = t2 -> next;
		}
		struct Node* nn = createNode(sum % 10);
		carry = sum/10;
		curr -> next = nn;
		curr = curr -> next;
	}
	return dummyNode->next;
}


