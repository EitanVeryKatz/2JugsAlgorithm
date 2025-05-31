#pragma once
#include "JugsProblemSolver.h"

class JugsDynamicSolver:public JugsProblemSolver
{
private:
	const int m_LargeJar;
	const int m_SmallJar;
	int BFS(vertice* i_Start, vertice* i_Goal) override;

public:
	JugsDynamicSolver(int i_LargeJugMaxCapacity, int i_SmallJugMaxCapacity, int i_IsRuntimeWanted)
	:m_LargeJar(i_LargeJugMaxCapacity),m_SmallJar(i_SmallJugMaxCapacity)
	{
		runTimeWanted = i_IsRuntimeWanted;
	}

};

