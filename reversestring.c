#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char data;
	struct Node* next;
}Node;
 
 Node* top; 

 void push(char c)
 {
 	Node* temp=(Node*)malloc(sizeof(Node));
 	temp->data=c;
 	temp->next=top;
 	top=temp;
 }

 void pop(char c[])
 {
 	Node* temp;
 	temp=top;
 	int i=0;
 	while(temp!=NULL)
 	{
 	//printf("%c",temp->data);
 		c[i]=temp->data;
 		i++;
 	    temp=temp->next;
    }
    printf("%s\n",c);
 }

int main()
{
	int i;
	char c[]={'h','e','l','l','o','\0'};
	for(i=0;i<5;i++)
		push(c[i]);
    pop(c);
}