#pragma once
#include "JugsProblemSolver.h"

class JugsDynamicSolver:JugsProblemSolver
{
private:

	const int m_LargeJar;
	const int m_SmallJar;
	int BFS(vertice* start, vertice* goal);
	list <edge*> GetAdjList(vertice u);
	map <vertice,string> *CalculateAdjList(vertice v);
public:

	JugsDynamicSolver(int L, int S, int T) :m_LargeJar(L),m_SmallJar(S)
	{
		runTimeWanted = T;
	}

	void Solve(int W) override;
};

