#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
    struct Node* link;
}Node;

Node* head;

void insert(int x)
{
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=x;
	temp->link=head;
	head=temp;
}

void print()
{
	Node* temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d, ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}

void Print(Node* p)
{
	if(p==NULL)
		return;
	printf("%d",p->data);
	Print(p->link);
}

void reverse_recur(Node* p)
{ 
	Node* temp;
	if(p->link==NULL)
	{
		head=p;
		return;
	}

	reverse_recur(p->link);
	temp=p->link;
	temp->link=p;
	p->link=NULL;
}

void insertpos(int x,int pos)
{
	int i;
	Node* temp=(Node*)malloc(sizeof(Node));
	Node *temp1,*temp2;
	temp->data=x;
	temp1=head;
	for(i=0;i<pos-2;i++)
	{
		temp1=temp1->link;
		temp2=temp1->link;
	}
	temp1->link=temp;
	temp->link=temp2;
}

void delete(int pos)
{
	int i;
	Node *temp,*temp1;
	if(pos==1)
		head=head->link;
	else
	{
		temp=head;
		for(i=0;i<pos-2;i++)
	{
		temp=temp->link;
		temp1=temp->link;
	}
	//printf("%d  %d\n",temp->data,temp1->data);
	temp->link=temp1->link;
	free(temp1);
    }
}
void reverse()
{
	Node *prev,*current,*next;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;

	}
	head=prev;
}

int main()
{
	insert(1);
	print();
	insert(2);
	print();

	insert(3);
	//print();
	insert(4);
	print();
	insertpos(5,3);
	print();
	delete(3);
	print();
	reverse_recur(head);
	print();
}
/*int main()
{
	Node* head;
	head=insert(1,head);
	print(head);
	head=insert(2,head);
	print(head);
	head=insert(3,head);
	print(head);
}*/
