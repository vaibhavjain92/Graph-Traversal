// DFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<list>
using namespace std;

class Graph
{
	// No. of vertices in a graph
	int V;
	// pointer to an adjacency list corresponding to each vertex
	list<int> *adj;
	void DFSUtil(int v, bool *visited); //recursive function to print out the element of graph
public: 
	Graph(int V); // constructor
	void addEdge(int v, int w); // add edge between v and w
	void DFS(); // loop through all the member of graph
};
void Graph::DFSUtil(int v, bool *visited)
{
	// Mark the current node as visited
	visited[v] = true;
	// print the current vertex
	// It keeps on printing whatever node is visited by the recursive function 
	cout << v << " ";
	// an iterator to iterate through all the adjacent vertices of the current vertex
	// if anyone if not visited visit it
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (!visited[*i])
		{
			// call the recursive function on the nodes which are not visited
			DFSUtil(*i, visited);
		}
	}
}
Graph::Graph(int V)
{
	this->V = V;// allocate the amount of vertices 
	adj = new list<int>[V]; // create the adjacency list corresponding to each vertex in the graph
}
void Graph::addEdge(int v, int w)
{
	// add w to the adjacency list of v
	adj[v].push_back(w);
}
void Graph::DFS()
{
	// create a boolean for all the vertices and mark all as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}
	//
	for (int i = 0; i < V; i++)
	{
		// if the node is not visited, call the recursive function to print out those vertices
		if (!visited[i])
		{
			DFSUtil(i, visited);
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

	cout << "Following is Depth First Traversal \n";
	g.DFS();
	cout << endl;
    return 0;
}

