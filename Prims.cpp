// Prims.cpp : Defines the entry point for the console application.
//
//Min function to return the index of the vertex having min distance from the adjacent
//prims function to run the prim algorithm
//which requires parent, ket, visitedSet, update adjacent distance
//print result function to show the minimum spanning tree

#include "stdafx.h"
#include<iostream>
#include<limits.h>
using namespace std;

#define V 5

int MinIndex(int key[], bool visitedSet[])
{
	int min_index, min = INT_MAX;
	for (int i = 0; i < V; i++)
	{
		if (!visitedSet[i] && key[i] < min)
		{
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void PrintResult(int parent[V], int graph[V][V])
{
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] << " - " << i << "\t " << graph[i][parent[i]] << endl;
	}
}
void Prim(int graph[V][V])
{
	int key[V];
	int parent[V];
	bool visitedSet[V];
	for (int i = 0; i < V; i++)
	{
		visitedSet[i] = false, key[i] = INT_MAX, parent[i] = -1;
	}

	key[0] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = MinIndex(key, visitedSet);

		visitedSet[u] = true;

		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] && !visitedSet[v] && graph[u][v] < key[v])
			{
				key[v] = graph[u][v];
				parent[v] = u;
			}
		}
	}
	PrintResult(parent, graph);
}
int main()
{
	/* Let us create the following graph
	2    3
	(0)--(1)--(2)
	|   / \   |
	6| 8/   \5 |7
	| /     \ |
	(3)-------(4)
	9          */
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 },
	};

	// Print the solution
	Prim(graph);

    return 0;
}

