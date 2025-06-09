/* Introduction to Software Testing,
 * Authors: Paul Ammann & Jeff Offutt
 * Chapter 4, section 4.2, page 164
 * Note:  BoundedQueue is a minor variation of Queue from Chapter 2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BoundedQueue
{
	int capacity;
	int size;
	int front;
	int back;
	int *elements;
}BoundedQueue; 

BoundedQueue * createQueue(int maxElements)
{
	BoundedQueue *q;
	if (maxElements < 0) {
		printf("Invalid size.\n");
		q = 0; //point to NULL
		return q;
	}
	
	q = (BoundedQueue *) malloc(sizeof(BoundedQueue));

	q->elements = (int *) malloc(sizeof(int)*maxElements);
	q->size = 0;
	q->capacity = maxElements;
	q->front = 0;
	q->back = 0;
	/* return the pointer */
	return q;
}

void enqueue(BoundedQueue *q, int e)
{

	if(q->size == q->capacity) {
		printf("Queue is Full\n");
	}
	else {
		q->size = q->size + 1;
		q->elements[q->back] = e;
		q->back = (q->back + 1) % q->capacity;
	}
}

int isFull(BoundedQueue *q) 
{
	return q->size == q->capacity;
}

int isEmpty(BoundedQueue *q) 
{
	return q->size == 0;
}

int dequeue(BoundedQueue *q)
{   
	int r;
	if (q->size == 0) {
		printf("Queue is already empty!\n");
		return -1;
	} else {
		q->size = q->size - 1;
		r = q->elements[(q->front % q->capacity)];
		q->front = (q->front + 1) % q->capacity;
		return r;
	}
}

void printBoundedQueue(BoundedQueue *q)
{
	int i, e;
	printf("[");
	for (i = 0; i < q->size; i++) {
		e = q->elements[(q->front + i) % q->capacity];
		printf("%d", e);
		if (i < q->size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main (int argc, char *argv[])
{ 
	driver(argc, argv);
	return 0;
}
