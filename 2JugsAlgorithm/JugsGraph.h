#pragma once
#include <list>
#include <utility> // for std::pair
#include <map>
#include<vector>
#include <string>
#define INFINITY -1
using namespace std;

typedef pair<int, int> vertice; // Represents the state of the jugs (x, y)
typedef pair<vertice*, string> edge;


class JugsGraphSolver
{
private:
	map <vertice, list <edge*> > Vertices; // Adjacency list representation
	map <vertice, edge> parent; // Map to store parent vertices for path reconstruction
	map <vertice, int> distance; // Map to store distances from the start vertex

	bool runTimeWanted;
	void MakeEmptyGraph(int L, int S);
	void AddEdge(vertice u, vertice v,string action);
	void SetUpVEdgesForJugs(int L, int S);
	int BFS(vertice* start, vertice* goal);
	list <edge*> GetAdjList(vertice u);
	

public:
	JugsGraphSolver(int L,int S, int T)
	{
		runTimeWanted = T;
		MakeEmptyGraph(L,S); // Initialize the graph with vertices based on jug capacitiesl
		SetUpVEdgesForJugs(L, S);
	}
	~JugsGraphSolver()
	{
		for (auto& v : Vertices)
		{
			for (auto& e : v.second)
			{
				delete e->first; // Free the vertice (state) itself
				delete e; // Free the edge itself

			}
		}
	}
	void Solve(int W, int& d);
};

