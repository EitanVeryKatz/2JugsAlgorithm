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
	map <vertice, list <vertice> > Adj; // Adjacency list representation
	map <vertice, vertice*> parent; // Map to store parent vertices for path reconstruction
	vector<vertice> Vertices; // Vector to store vertices for BFS
	map <vertice, int> distance; // Map to store distances from the start vertex

	void MakeEmptyGraph(int n);
	void AddEdge(vertice u, vertice v);
	void SetUpVEdgesForJugs(int L, int S);
	int BFS(vertice start, vertice goal);

public:
	JugsGraph(int L,int S)
	{
		MakeEmptyGraph(L); // Initialize the graph with vertices based on jug capacitiesl
		SetUpVEdgesForJugs(L, S);
	}

	list <vertice> GetAdjList(vertice u);
	list<vertice> Solve(int W, int& d);
	
};

