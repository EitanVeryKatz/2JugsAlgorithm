#pragma once
#include <chrono>
#include <string>
#include <iostream>
#include <utility> // for std::pair
#include <list>
#include <map>
#include <queue>
#include<vector>
#define INFINITY -1

using namespace std;

typedef pair<int, int> vertice; // Represents the state of the jugs (x, y)
typedef pair<vertice, string> edge;

class JugsProblemSolver
{
protected:
	bool runTimeWanted;
	map <vertice, edge> parent; // Map to store parent vertices for path reconstruction
	map <vertice, int> distance; // Map to store distances from the start vertex
	int virtual BFS(vertice* start, vertice* goal) = 0;
	map <vertice, string>* CalculateAdjList(vertice v, int smallJarMaxCapacity, int largeJarMaxCapacity);


public:

	void virtual Solve(int W);
	virtual ~JugsProblemSolver() {}
};

