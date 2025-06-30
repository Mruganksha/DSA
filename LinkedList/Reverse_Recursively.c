//reverese recursively

struct Node{
	int data;
	struct Node* next;
};

struct Node* reverse(struct Node* head){
   if(head == NULL || head-> next == NULL){
   	  return head;
   }
   
   struct Node* nHead = reverse(head -> next);
   
   head -> next -> next = head;
   head -> next = NULL;
   
   return nHead;
}
