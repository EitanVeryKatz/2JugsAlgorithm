#include "JugsGraph.h"
#include <list>
#include <queue>
#include <map>
#include <utility> // for std::pair
#include <unordered_set>
#include <iostream>


void JugsGraph::MakeEmptyGraph(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			vertice v = make_pair(i, j);
			Vertices[v] = list<vertice*>(); // Initialize the adjacency list for each vertice
		}
	}
}

list<vertice*> JugsGraph::GetAdjList(vertice u)
{
	//returns the adjacency list of the graph sorted by value
	list<vertice*> adjList = Vertices[u];
	adjList.sort(); // Sort the adjacency list by value
	return adjList;
}

void JugsGraph::AddEdge(vertice u, vertice v) 
{
	cout << "Adding edge from (" << u.first << ", " << u.second << ") to (" << v.first << ", " << v.second << ")\n"; // Debug output
	vertice* newNeighbor = new vertice;
	newNeighbor->first = v.first;
	newNeighbor->second = v.second;
	Vertices[u].push_back(newNeighbor);
}

int JugsGraph::BFS(vertice* start, vertice* goal) 
{
	// Implement BFS to find the shortest path from start to goal
	queue<vertice*> queue;

	for (auto& v : Vertices)
	{
		distance[v.first] = INFINITY; // Initialize distances to -1
		parent[v.first] = nullptr; // Initialize parent to an invalid state
	}

	distance[*start] = 0; // Distance to start is 0
	parent[*start] = nullptr; // Start has no parent
	queue.push(start);

	while (!queue.empty())
	{
		vertice* current = queue.front();
		queue.pop();
		cout << "Current: (" << current->first << ", " << current->second << ")\n"; // Debug output

		if (*current == *goal)
		{
			// Reconstruct the path
			return distance[*current]; // Return the distance to the goal
		}
		else 
		{
			for (auto& neighbor : GetAdjList(*current))
			{
				if (distance[*neighbor] == INFINITY) // If not visited
				{
					cout << "	Visiting: (" << neighbor->first << ", " << neighbor->second << ")\n"; // Debug output
					cout << "	Setting Parent of (" << neighbor->first << ", " << neighbor->second << ") to (" << current->first << ", " << current->second << ")\n"; // Debug output
					
					distance[*neighbor] = distance[*current] + 1; // Update distance
					parent[*neighbor] = current; // Set parent
					
					queue.push(neighbor); // Enqueue the neighbor
				}
			}
		}
	}
}

void JugsGraph::SetUpVEdgesForJugs(int L, int S)
{
	for (auto& v : Vertices) {
		int LargeJug = v.first.first;
		int SmallJug = v.first.second;

		
		vector<vertice> potentialNeighbors;
		if (LargeJug < L && SmallJug < S) {
			// Both jugs can be filled
			potentialNeighbors.push_back(make_pair(L, SmallJug)); // Fill large jug
			potentialNeighbors.push_back(make_pair(LargeJug, S)); // Fill small jug
		}
		if (LargeJug > 0 && SmallJug < S) {
			// Large jug can be poured into small jug
			int pourIntoSmall = min(LargeJug, S - SmallJug);
			potentialNeighbors.push_back(make_pair(LargeJug - pourIntoSmall, SmallJug + pourIntoSmall)); // Pour from large to small
		}
		if (SmallJug > 0 && LargeJug < L) {
			// Small jug can be poured into large jug
			int pourIntoLarge = min(SmallJug, L - LargeJug);
			potentialNeighbors.push_back(make_pair(LargeJug + pourIntoLarge, SmallJug - pourIntoLarge)); // Pour from small to large
		}
		if (LargeJug > 0) {
			potentialNeighbors.push_back(make_pair(0, SmallJug)); // Empty large jug
		}
		if (SmallJug > 0) {
			potentialNeighbors.push_back(make_pair(LargeJug, 0)); // Empty small jug
		}

		// Add edges only if the target vertex exists in the graph
		for (const auto& neighbor : potentialNeighbors) {
			
				AddEdge(v.first, neighbor);

		}

	}
}

list<vertice> JugsGraph::Solve(int W, int& d)
{
	// Solve the jugs problem using BFS
	vertice start = make_pair(0, 0); // Starting state (both jugs empty)
	vertice goal = make_pair(W, 0); // Goal state (large jug has W liters, small jug is empty)

	d = BFS(&start, &goal); // Get the distance to the goal

	if (d == INFINITY) {
		return list<vertice>(); // No solution found
	}

	// Reconstruct the path from start to goal
	list<vertice> path;
	vertice current = goal;

	while (current != start) {
		path.push_front(current);
		current = *parent[current]; // Move to parent
	}
	path.push_front(start); // Add the start state

	return path; // Return the path from start to goal
}

