#include "JugsGraphSolver.h"
#include <list>

#include <map>




void JugsGraphSolver::MakeEmptyGraph(int i_LargeJugMaxCapacity,int i_SmallJugMaxCapacity)
{
	for (int i = 0; i <= i_LargeJugMaxCapacity; ++i)
	{
		for (int j = 0; j <= i_SmallJugMaxCapacity; ++j)
		{
			vertice newVertice = make_pair(i, j);
			m_VerticesAdjList[newVertice] = list<edge*>(); // Initialize the adjacency list for each vertice
		}
	}
}

list<edge*> JugsGraphSolver::GetAdjList(vertice i_TargetVertice)
{
	//returns the adjacency list of the graph sorted by value
	list<edge*> adjList = m_VerticesAdjList[i_TargetVertice];
	adjList.sort(); // Sort the adjacency list by value
	return adjList;
}

void JugsGraphSolver::AddEdge(vertice i_SourceVertice, vertice i_DestinationVertice,string i_ActionDescription) 
{
	vertice* newNeighbor = new vertice;
	edge* newEdge = new edge;
	newEdge->first.first = i_DestinationVertice.first; // Set the edge's source to u	
	newEdge->first.second = i_DestinationVertice.second;
	newEdge->second = i_ActionDescription; // Set the edge's destination to v
	m_VerticesAdjList[i_SourceVertice].push_back(newEdge);
}

int JugsGraphSolver::BFS(vertice* start, vertice* goal) 
{
	// Implement BFS to find the shortest path from start to goal
	queue<vertice> queue;

	for (auto& v : m_VerticesAdjList)
	{
		distance[v.first] = INFINITY; // Initialize distances
	}

	distance[*start] = 0; // Distance to start is 0
	queue.push(*start);

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
			for (auto& edge : GetAdjList(current))
			{
				vertice neighbor = edge->first; // Get the neighbor vertice from the edge
				if (distance[neighbor] == INFINITY) // If not visited
				{
					distance[neighbor] = distance[current] + 1; // Update distance
					parent[neighbor].first = current; // Set parent
					parent[neighbor].second = edge->second;
					
					queue.push(neighbor); // Enqueue the neighbor
				}
			}
		}
	}

	return distance[*goal]; // Return the distance to the goal
}

void JugsGraphSolver::SetUpVEdgesForJugs(int i_LargeJugMaxCapacity, int i_SmallJugMaxCapacity)
{
	for (auto& verticeEntry : m_VerticesAdjList) {
		map <vertice, string>* potentialNeighbors = CalculateAdjList(verticeEntry.first, i_SmallJugMaxCapacity, i_LargeJugMaxCapacity);

		// Add edges only if the target vertex exists in the graph
		for (const auto& neighbor : *potentialNeighbors) {
			AddEdge(verticeEntry.first, neighbor.first, neighbor.second);
		}

		delete potentialNeighbors; // Clean up the dynamically allocated memory
	}
}



