#include<iostream>
#include<list>
using namespace std;

class Graph{
int v;
list<int> *adj;
public:
	Graph(int v);
	void addedge(int s,int d);
	void bfs(int s);
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addedge(int s,int d)
{
	adj[s].push_back(d);
}

void Graph::bfs(int s)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	list<int> queue;
	queue.push_back(s);
	visited[s]=true;
	list<int>::iterator i;
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<"\t";
		queue.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
        	if(!visited[*i])
        	{
        		visited[*i]=true;
        		queue.push_back(*i);
        	}
        }
	}
	cout<<"\n";
}

main()
{
	Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    cout<<"Breadth traversal: ";
    g.bfs(2);
}