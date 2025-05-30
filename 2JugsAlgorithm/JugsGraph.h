#pragma once
#include <list>
#include <utility> // for std::pair
#include <map>
#include<vector>
#define INFINITY -1
using namespace std;

typedef pair<int, int> vertice; // Represents the state of the jugs (x, y)


class JugsGraph
{
private:
	map <vertice, list <vertice*> > Vertices; // Adjacency list representation
	map <vertice, vertice*> parent; // Map to store parent vertices for path reconstruction
	map <vertice, int> distance; // Map to store distances from the start vertex

	void MakeEmptyGraph(int n);
	void AddEdge(vertice u, vertice v);
	void SetUpVEdgesForJugs(int L, int S);
	int BFS(vertice* start, vertice* goal);

public:
	JugsGraph(int L,int S)
	{
		MakeEmptyGraph(L); // Initialize the graph with vertices based on jug capacitiesl
		SetUpVEdgesForJugs(L, S);
	}
	~JugsGraph()
	{
		for (auto& v : Vertices)
		{
			for(auto& e: v.second)
			{
				delete e; // Free dynamically allocated memory for edges
			}
		}
	}

	list <vertice*> GetAdjList(vertice u);
	list<vertice> Solve(int W, int& d);
	
};

