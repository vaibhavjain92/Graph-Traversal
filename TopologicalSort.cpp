// TopologicalSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<list>
using namespace std;

// Create a class graph
// add data member and tsutil func along with const, addEdge, ts
// tsutil will be called until no adjacent vertex left and then added to the stack
// ts is called for every vertex which has not been visited which calls tsutil and finally prints stack

class Graph
{
	int V;
	list<int> *adj;
	void TSUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void TS();
};

void Graph::TSUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;

	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (!visited[*i])
		{
			TSUtil(*i, visited, Stack);
		}
	}
	Stack.push(v);
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
void Graph::TS()
{
	stack<int>Stack;
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			TSUtil(i, visited, Stack);
		}
	}

	while (!Stack.empty())
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
	cout << endl;
}
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph n" << endl;
	g.TS();
    return 0;
}

