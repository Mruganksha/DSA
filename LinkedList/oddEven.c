//odd even 
//Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

//The first node is considered odd, and the second node is even, and so on.

struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* odd = head;
   
   if(head == NULL || head -> next == NULL){
    return head;
   }

    struct ListNode* even = head -> next;
    struct ListNode* evenHead = head -> next;

    while(even != NULL && even->next != NULL){
        odd -> next = odd -> next -> next;
        even -> next = even -> next -> next;
        odd = odd -> next;
        even = even -> next;
    }
    odd -> next = evenHead;
    return head;
}
