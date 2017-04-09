#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
	int top;
	int *array;
    unsigned capacity;
}Stack;

Stack* createStack(unsigned capacity)
{
	Stack* stack=(Stack*)malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	return stack;
}
int isFull(Stack* stack)
{
	return stack->top==(stack->capacity)-1;
}
int isEmpty(Stack* stack)
{
	return stack->top==-1;
}

void push(Stack* stack,int n)
{
	if(isFull(stack))
		return;
	stack->array[++stack->top]=n;
}

int pop(Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int peep(Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

int main()
{
    Stack* stack;
	stack=createStack(5);
	push(stack,3);
	push(stack,6);
	push(stack,9);
	printf("%d\n",pop(stack));
	printf("%d\n",peep(stack));
}