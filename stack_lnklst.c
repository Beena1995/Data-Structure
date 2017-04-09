#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
	int data;
	struct Stack* next;
}Stack;
 Stack* top=NULL;

void push(int x)
{
	Stack* stack=(Stack*)malloc(sizeof(Stack));
	stack->data=x;
	stack->next=top;
	top=stack;
}

void pop()
{
	if(top==NULL)
		return;
	Stack* temp;
	temp=top;
	top=temp->next;
	free(temp);
}

