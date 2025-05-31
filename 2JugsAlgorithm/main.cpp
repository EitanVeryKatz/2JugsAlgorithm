#include <iostream>
#include "JugsGraphSolver.h"
#include "JugsDynamicSolver.h"
#include <stdlib.h>
#define FirstAlgotrithm 1
#define SecondAlgotrithm 2

void main() 
{
	int L, S, W, T, A;
	/*std::cout << "Enter the capacity of the large jug (L): ";*/
	std::cin >> L;
	//std::cout << "Enter the capacity of the small jug (S): ";
	std::cin >> S;
	//std::cout << "Enter the target amount of water (W): ";
	std::cin >> W;
	//cout << "enter algo type: ";
	std::cin >> A;
	std::cin >> T;


	if (L <= 0 || S <= 0 || W < 0 || T < 0 || (A != FirstAlgotrithm && A != SecondAlgotrithm)||T>1){
		std::cout << "invalid input.";
		exit(1);
	}
	JugsProblemSolver* solver = nullptr;
	solver = (A == FirstAlgotrithm ? (JugsProblemSolver*)new JugsGraphSolver(L, S, T) : (JugsProblemSolver*)new JugsDynamicSolver(L, S, T));
	solver->Solve(W);

}