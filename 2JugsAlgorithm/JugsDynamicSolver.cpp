#pragma once
#include "JugsDynamicSolver.h"




int JugsDynamicSolver::BFS(vertice* i_Start, vertice* i_Goal)
{
	// Implement BFS to find the shortest path from start to goal
	queue<vertice> queue;

	distance[*i_Start] = 0; // Distance to start is 0
	queue.push(*i_Start);
	distance[*i_Goal] = INFINITY;
	while (!queue.empty())
	{
		vertice current = queue.front();

		queue.pop();
		if (current == *i_Goal)
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

	return distance[*i_Goal]; // Return the distance to the goal
}

