#include <iostream>
#include "JugsGraph.h"

void main() 
{
	int L, S, W;
	std::cout << "Enter the capacity of the large jug (L): ";
	std::cin >> L;
	std::cout << "Enter the capacity of the small jug (S): ";
	std::cin >> S;
	std::cout << "Enter the target amount of water (W): ";
	std::cin >> W;

	JugsGraph graph(L, S);
	int distance = 0;
	list<vertice> path = graph.Solve(W, distance);

	if (distance != INFINITY) {
		std::cout << "Minimum steps to measure " << W << " units: " << distance << "\n";
		std::cout << "Path: ";
		for (const auto& v : path) {
			std::cout << "(" << v.first << ", " << v.second << ") ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << "It's not possible to measure " << W << " units with the given jugs.\n";
	}
}