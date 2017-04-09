#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* head;

void insertatHead(int x)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	if(head==NULL)
	{
		temp->next=head;
		head=temp;
		temp->data=x;
		temp->prev=NULL;
		return;
	}
	temp->data=x;
	temp->next=head;
	head=temp;
	temp->next->prev=temp;
	temp->prev=NULL;
}

void reverseprint()
{
	Node* temp=head;
	while(temp->next!=NULL)          //linked list
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
int main()
{
	insertatHead(1);
	reverseprint();
	insertatHead(2);
	reverseprint();

	insertatHead(3);
	//print();
	insertatHead(4);
	reverseprint();
}