#include<iostream>
#include<stdlib.h>
using namespace std;

struct lnklst{
	int data;
	lnklst* next;
};

struct lst{
	lnklst *head;
};

struct Graph{
	int v;
	lst* arr;
};

lnklst* createnode(int data)
{
	lnklst* temp=new lnklst();
	temp->data=data;
	temp->next=NULL;
	return temp;
}

Graph* creategraph(int s)
{
	Graph* graph=new Graph();
	graph->v=s;
    graph->arr=new lst[s];
	int i;
	for(i=0;i<graph->v;i++)
	{
		graph->arr[i].head=NULL;
	}
	return graph;
}

void addedge(Graph* graph,int src,int dest)
{
	lnklst* newnode=createnode(dest);
	newnode->next=graph->arr[src].head;
	graph->arr[src].head=newnode;

	newnode=createnode(src);
	newnode->next=graph->arr[dest].head;         //if undirected graph
	graph->arr[dest].head=newnode;

}

void printgraph(Graph* graph)
{
	lnklst* temp;
	int i;
	for(i=0;i<graph->v;i++)
	{
		temp=graph->arr[i].head;
		while(temp)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		cout<<"\n";
	}
}

main()
{
	Graph* graph=creategraph(5);
	addedge(graph,0,1);
	addedge(graph,0,4);
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,1,4);
	addedge(graph,2,3);
	addedge(graph,3,4);
	printgraph(graph);
}