#pragma once

#include <string>
#include <utility> // for std::pair
#include <list>
#include <map>
#include<vector>
#define INFINITY -1

using namespace std;

typedef pair<int, int> vertice; // Represents the state of the jugs (x, y)
typedef pair<vertice*, string> edge;

class JugsProblemSolver
{
protected:
	bool runTimeWanted;

public:
	void virtual Solve(int W) = 0;
	virtual ~JugsProblemSolver() {}
};

