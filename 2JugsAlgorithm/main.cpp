#include <iostream>
#include "JugsGraphSolver.h"
#include "JugsDynamicSolver.h"

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


	
	JugsGraphSolver g(L, S, T);
	g.Solve(W);
	JugsDynamicSolver d(L, S, T);
	d.Solve(W);

}