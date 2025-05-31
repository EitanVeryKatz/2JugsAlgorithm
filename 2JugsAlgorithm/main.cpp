#include <iostream>
#include "JugsGraphSolver.h"
#include "JugsDynamicSolver.h"
#include <stdlib.h>
#define FirstAlgotrithm 1
#define SecondAlgotrithm 2

int main()
{
	int L, S, W, T, A;
	std::cin >> L;
	std::cin >> S;
	std::cin >> W;
	std::cin >> A;
	std::cin >> T;


	if (L <= 0 || S <= 0 || W < 0 || T < 0 || (A != FirstAlgotrithm && A != SecondAlgotrithm)||T>1||S>L){
		std::cout << "invalid input.";
		exit(1);
	}

	JugsProblemSolver* solver = nullptr;
	solver = (A == FirstAlgotrithm ? (JugsProblemSolver*)new JugsGraphSolver(L, S, T) : (JugsProblemSolver*)new JugsDynamicSolver(L, S, T));
	solver->Solve(W);

}