#pragma once
#include "JugsProblemSolver.h"

class JugsDynamicSolver:public JugsProblemSolver
{
private:

	const int m_LargeJar;
	const int m_SmallJar;
	int BFS(vertice* start, vertice* goal) override;
	list <edge*> GetAdjList(vertice u);
public:

	JugsDynamicSolver(int L, int S, int T) :m_LargeJar(L),m_SmallJar(S)
	{
		runTimeWanted = T;
	}

};

