//queue implementation using array

#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int *arr;
	int front;
	int rear;
	int capacity;
};

struct Queue* createQueue(int capacity){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q -> capacity = capacity;
	q -> front = 0;
	q -> rear = -1;
	q -> arr = (int*)malloc(capacity * sizeof(int));
	return q;
}

int isEmpty(struct Queue* q){
	return q -> front > q -> rear;
}

void enqueue(struct Queue* q, int x){
	if(q -> rear < q -> capacity - 1){
		q -> arr[++q->rear] = x;
	}
}

void dequeue(struct Queue* q){
	if(!isEmpty(q)){
		q->front++;
	}
}

int getFront(struct Queue* q){
	return isEmpty(q) ? -1 : q->arr[q->front];
}

void display(struct Queue* q){
	for(int i = q->front; i <= q->rear; i++){
		printf("%d ", q->arr[i]);
	}
	printf("\n");
}

int main() {
    struct Queue* q = createQueue(100);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", getFront(q));
    dequeue(q);
    enqueue(q, 4);
    display(q);
    return 0;
}
