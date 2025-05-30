#pragma once
#include "JugsProblemSolver.h"

class JugsDynamicSolver:JugsProblemSolver
{
private:

	const int LargeJar;
	const int SmallJar;

public:

	JugsDynamicSolver(int L, int S, int T) :LargeJar(L),SmallJar(S)
	{
		runTimeWanted = T;
	}

	void Solve(int W) override;
};

