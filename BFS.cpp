// BFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

class Graph
{
	//no. of vertices
	int V;
	//adjacency pointer corresponding to each vertex list
	list<int> *adj;
public:
	Graph(int x) { V = x; adj = new list<int>[x]; } //constructor
	void addEdge(int v, int w); //add edges to the given vertex
	void BFS(int s); // prints out each layer of the graph
};

void Graph::addEdge(int v, int w)
{
	// add the element w to the adjacency list of vertex v
	// it meand adding an edge to it
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	
	//create a visited boolean of all the vertices
	bool *visited = new bool[V];
	// mark all visited false
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	
	// list to store the adjacent members
	list<int> queue;
	// start the queue with the source
	queue.push_back(s);
	cout << "in BFS" << endl;
	visited[s] = true; // mark the visited true for the source
	
	// iterator to iterate through the adjacent list of each vertex
	// if the adjacent vertex is not visited , mark it visited and add it to the queue
	list<int>::iterator i;
	// loop till the queue becomes empty
	while (!queue.empty())
	{
		
		// s will be the element in the front of the queue
		s = queue.front();
		cout << s << " "; // print s
		queue.pop_front(); // pop the front element of the queue
		// check if the adjacent vertex has been visited or not, if not mark them visited and add them to the queue
		for (i = adj[s].begin(); i != adj[s].end(); i++)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal"
		<< "(starting from vertex 2)" << endl;
	g.BFS(2);

    return 0;
}

