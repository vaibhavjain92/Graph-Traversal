// Dijkstras.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<limits.h>
#include<stdio.h>
using namespace std;

#define V 9

int minDistIndex(int dist[], bool sptSet[])
{
	// Initialize the min distance and minimum index
	int min = INT_MAX, min_ind;
	//loop through all the indexes which are not confirmed in shortest path 
	//and whose distance is less than the  minimum
	for (int i = 0; i < V; i++)
	{
		if (sptSet[i] == false && dist[i] < min)
		{
			min = dist[i];
			min_ind = i;
		}
	}
	return min_ind;
}

//prints out the result with minimum distances for every index
void printResult(int dist[])
{
	cout << "Minimum distances for every index "<< endl;
	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}
}

//Main Dijkstra's Implementation
void Dijkstras(int graph[V][V], int src)
{
	// an output array to keep track of all the shortest distances from src to i
	int dist[V];

	// a shortest path boolean array which keeps track of all the indices for which shortest path has been confirmed
	bool sptSet[V];

	//A parent array to keep track from which previous node the shortest path have been taken
	int parent[V] = {0};

	//initialize all distance to maximum and all booleans to false
	for (int i = 0; i < V; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	//distance from src to src is always zero;
	dist[src] = 0;

	// find minimum distances of all indexes
	//main loop of dijkstras
	for (int count = 0; count < V - 1; count++)
	{
		//get the minimum index
		int u = minDistIndex(dist, sptSet);

		//mark the minimum index as finalized and put it in the shortest path set
		sptSet[u] = true;

		//update the distance of adjacent neighbors of u
		// if the neighbor is not in shortest path set, has an edge from u to v, and dist[u[ + w< dist[v]
		for (int v = 0; v < V; v++)
		{
			if (sptSet[v] == false && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
				parent[v] = u;
			}
		}
	}
	printResult(dist);
}
int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	Dijkstras(graph, 0);

	return 0;
}

