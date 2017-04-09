#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
	int capacity;
	int *array
	int front;
	int rear;
}queue;

queue* creteQueue()
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	queue->array=(queue*)malloc(capacity*sizeof(int));
	return q;
}

void enqueue(int x,queue *q,int n)
{
	if(queue->front==-1&&queue->rear==-1)
		{
			queue->front=0;
			queue->rear=0;
		}
	if((queue->rear+1)%n==queue->front)
		return;
	else
	{
		q->rear=(q->rear++)%n;
		
	}
	queue->array[rear]=x;

}

void dequeue(queue* q,int n)
{
	if(queue->front==-1&&queue->rear==-1)
		return;
	if(q->front==q->rear)
	{
		queue->front=-1;
		queue->rear=-1;
	}	
	else
		queue->front=((queue->front)+1)%n;
}