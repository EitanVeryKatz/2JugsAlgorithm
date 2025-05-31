#include "JugsGraphSolver.h"
#include <list>

#include <map>




void JugsGraphSolver::MakeEmptyGraph(int L,int S)
{
	for (int i = 0; i <= L; ++i)
	{
		for (int j = 0; j <= S; ++j)
		{
			vertice v = make_pair(i, j);
			Vertices[v] = list<edge*>(); // Initialize the adjacency list for each vertice
		}
	}
}

list<edge*> JugsGraphSolver::GetAdjList(vertice u)
{
	//returns the adjacency list of the graph sorted by value
	list<edge*> adjList = Vertices[u];
	adjList.sort(); // Sort the adjacency list by value
	return adjList;
}

void JugsGraphSolver::AddEdge(vertice u, vertice v,string action) 
{
	vertice* newNeighbor = new vertice;
	edge* newEdge = new edge;
	newEdge->first.first = v.first; // Set the edge's source to u	
	newEdge->first.second = v.second;
	newEdge->second = action; // Set the edge's destination to v
	Vertices[u].push_back(newEdge);
}

int JugsGraphSolver::BFS(vertice* start, vertice* goal) 
{
	// Implement BFS to find the shortest path from start to goal
	queue<vertice> queue;

	for (auto& v : Vertices)
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

void JugsGraphSolver::SetUpVEdgesForJugs(int L, int S)
{
	for (auto& v : Vertices) {
		map <vertice, string>* potentialNeighbors = CalculateAdjList(v.first, S, L);

		//int LargeJug = v.first.first;
		//int SmallJug = v.first.second;
		//map<vertice, string> actions; // Map to store actions for each edge

		//
		//vector<vertice> potentialNeighbors;
		//if (SmallJug < S) {

		//	vertice fillSmall = make_pair(LargeJug, S);// Fill small jug
		//	potentialNeighbors.push_back(fillSmall);
		//	actions[fillSmall] = "Fill small jug"; // Action for filling small jug
		//}
		//if (LargeJug < L) {
		//	vertice fillLarge = make_pair(L, SmallJug);// Fill large jug
		//	potentialNeighbors.push_back(fillLarge);
		//	actions[fillLarge] = "Fill large jug"; // Action for filling large jug
		//}
		//if (LargeJug > 0 && SmallJug < S) {
		//	// Large jug can be poured into small jug
		//	int pourIntoSmall = min(LargeJug, S - SmallJug);
		//	vertice pourLargeToSmall = make_pair(LargeJug - pourIntoSmall, SmallJug + pourIntoSmall);
		//	potentialNeighbors.push_back(pourLargeToSmall); // Pour from large to small
		//	actions[pourLargeToSmall] = "Pour from large jug to small jug"; // Action for pouring from large to small jug
		//}
		//if (SmallJug > 0 && LargeJug < L) {
		//	// Small jug can be poured into large jug
		//	int pourIntoLarge = min(SmallJug, L - LargeJug);
		//	vertice pourSmallToLarge = make_pair(LargeJug + pourIntoLarge, SmallJug - pourIntoLarge);
		//	potentialNeighbors.push_back(pourSmallToLarge); // Pour from small to large
		//	actions[pourSmallToLarge] = "Pour from small jug to large jug"; // Action for pouring from small to large jug
		//}
		//if (LargeJug > 0) {
		//	vertice emptyLarge = make_pair(0, SmallJug);
		//	actions[emptyLarge] = "Empty large jug"; // Action for emptying large jug
		//	potentialNeighbors.push_back(emptyLarge);
		//}
		//if (SmallJug > 0) {
		//	vertice emptySmall = make_pair(LargeJug, 0);
		//	actions[emptySmall] = "Empty small jug"; // Action for emptying small jug
		//	potentialNeighbors.push_back(emptySmall);
		//}

		// Add edges only if the target vertex exists in the graph
		for (const auto& neighbor : *potentialNeighbors) {
			
				AddEdge(v.first, neighbor.first,neighbor.second);

		}

		delete potentialNeighbors; // Clean up the dynamically allocated memory

	}
}



