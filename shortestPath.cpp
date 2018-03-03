// shortestPath.cpp : Defines the entry point for the console application.
// By: Vaibhav Jain
// To find the shortest path in a maze
// check if start is not the goal 
// intialize visited array and a queue for BFS
// put the first point in the queue along with its distance from start
// run the loop
// check if the point is not equal to the goal -> if it is, return the dist
// else, pop this point from the queue
// add its adjacent element to the list along with distance if they are valid, not visited and path exist
// if the loop ends without returning, return iNT_MAX, path doesn't exist

#include "stdafx.h"
#include <iostream>
#include <list>

#define ROW 9
#define COL 10

//to store matrix cell cordinates
struct Point {
	int x;
	int y;
};

struct NodeDist {
	Point cell;
	int dist;
};

bool isValid(int x, int y)
{
	if (x >= 0 && x < ROW && y >= 0 && y < COL)
		return true;
	return false;
}

int rows[] = { -1, 0, 1, 0 };
int cols[] = { 0, -1, 0, 1 };

int shortestPath(int maze[ROW][COL], Point start, Point goal)
{
	// check if its already not in goal
	if (start.x == goal.x && start.y == goal.y)
		return 0;
	// start the BFS
	
	bool visited[ROW][COL] = { false };
	// create a queue, push the first element in the queue. Also mark the first element to be visited
	
	std::list<NodeDist> queue;
	queue.push_back({ start,0 });

	// start the loop until the queue in empty or it reaches the goal
	while (!queue.empty())
	{
		NodeDist d = queue.front();
		Point p = d.cell;
		if (p.x == goal.x && p.y == goal.y)
			return d.dist;

		queue.pop_front();
		// push the adjacent element is queue if they are 1 and not visited
		for (int i = 0; i < 4; i++)
		{
			int x = p.x + rows[i];
			int y = p.y + cols[i];
			Point adj = { x,y };
			if (isValid(x, y) && maze[x][y] && !visited[x][y])

				queue.push_back({ adj, d.dist + 1 });
		}
	}
	return INT_MAX;
}
int main()
{
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};

	Point source = { 0, 0 };
	Point dest = { 4, 4 };

	int dist = shortestPath(mat, source, dest);

	if (dist != INT_MAX)
		std::cout << "Shortest Path is " << dist << std::endl;
	else
		std::cout << "Shortest Path doesn't exist";

    return 0;
}

