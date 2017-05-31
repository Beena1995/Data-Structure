#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int v;
	list<int> *adj;
	 void dfsutil(int s,bool *visited);
public:
	Graph(int v);
	void dfs(int s);
	void addedge(int s,int d);
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph:: addedge(int s,int d)
{
	adj[s].push_back(d);
}

void Graph::dfsutil(int s,bool *visited)
{
	visited[s]=true;
	cout<<s<<"\t";
	list<int>::iterator i;
	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
			dfsutil(*i,visited);
	}
}

void Graph::dfs(int s)
{
	bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
    	visited[i]=false;
    }
    dfsutil(s,visited);
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
    cout<<"Depth traversal: ";
    g.dfs(2);
}