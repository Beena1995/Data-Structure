#include<iostream>
#include<stack>
using namespace std;

typedef struct Node{
	int data;
    struct Node* link;
}Node;

typedef struct Stack{
	int data;
	struct Stack* next;
}Stack;
Stack* top=NULL;

Node* head;

void insert(int x)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->link=head;
	head=temp;
}

void reverse()
{
	stack<Node*> s;
	Node* temp=head;
	while(temp!=NULL)
	{
		s.push(temp);
		temp=temp->next;
	}
	head=s.top();
	temp=s.top();
	while(!s.empty())
	{
		s.pop();
		temp->next=s.top();
		temp=temp->next;
	}
	temp->next=NULL;

}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	reverse();

}