#pragma once
#include "JugsDynamicSolver.h"




int JugsDynamicSolver::BFS(vertice* start, vertice* goal)
{
	// Implement BFS to find the shortest path from start to goal
	queue<vertice> queue;
	distance[*start] = 0; // Distance to start is 0
	queue.push(*start);
	distance[*goal] = INFINITY;

	while (!queue.empty())
	{
		vertice current = queue.front();
		queue.pop();
		if (current == *goal)
		{
			// Reconstruct the path
			break;

		}
		else
		{
			map <vertice, string>* neighbors = CalculateAdjList(current,m_SmallJar,m_LargeJar); // Get neighbors of current vertice
			for (auto& edge : *neighbors)
			{
				vertice neighbor = edge.first; // Get the neighbor vertice from the edge
				if (parent.find(neighbor) == parent.end()) // If not visited
				{
					distance[neighbor] = distance[current] + 1; // Update distance
					parent[neighbor].first = current; // Set parent
					parent[neighbor].second = edge.second;

					queue.push(neighbor); // Enqueue the neighbor
				}
			}

			delete neighbors; // Clean up the dynamically allocated memory for neighbors
		}
	}

	return distance[*goal]; // Return the distance to the goal
}

