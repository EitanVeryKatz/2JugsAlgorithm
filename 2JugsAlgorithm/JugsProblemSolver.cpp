#include "JugsProblemSolver.h"

void JugsProblemSolver::Solve(int W) {

	// Solve the jugs problem using BFS
	auto startTimer = chrono::high_resolution_clock::now();

	vertice start = make_pair(0, 0); // Starting state (both jugs empty)
	vertice goal = make_pair(W, 0); // Goal state (large jug has W liters, small jug is empty)

	int d = BFS(&start, &goal); // Get the distance to the goal

	auto end = chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - startTimer);

	if (d == INFINITY) {
		std::cout << "No solution." << endl;
	}
	else {
		// Reconstruct the path from start to goal
		list<string> path;
		vertice current = goal;

		while (current != start) {
			path.push_front(parent[current].second);
			current = parent[current].first; // Move to parent
		}

		std::cout << "Number of operations: " << d << "\n";
		std::cout << "Operations: " << endl;
		for (const auto& action : path) {
			std::cout << action << endl;
		}
	}

	if (runTimeWanted) {
		std::cout << "Function took " << duration.count() << " microseconds." << std::endl;
	}

	std::cout << "\n";

}

map <vertice, string>* JugsProblemSolver::CalculateAdjList(vertice v,int smallJarMaxCapacity,int largeJarMaxCapacity)
{

	int LargeJug = v.first;
	int SmallJug = v.second;

	map<vertice, string>* potentialNeighbors = new map<vertice, string>;
	if (SmallJug < smallJarMaxCapacity) {

		vertice fillSmall = make_pair(LargeJug, largeJarMaxCapacity);// Fill small jug
		(*potentialNeighbors)[fillSmall] = "Fill small jug"; // Action for filling small jug
	}
	if (LargeJug < largeJarMaxCapacity) {
		vertice fillLarge = make_pair(largeJarMaxCapacity, SmallJug);// Fill large jug
		(*potentialNeighbors)[fillLarge] = "Fill large jug";
	}
	if (LargeJug > 0 && SmallJug < smallJarMaxCapacity) {
		// Large jug can be poured into small jug
		int pourIntoSmall = min(LargeJug, smallJarMaxCapacity - SmallJug);
		vertice pourLargeToSmall = make_pair(LargeJug - pourIntoSmall, SmallJug + pourIntoSmall);
		(*potentialNeighbors)[pourLargeToSmall] = "Pour from large jug to small jug"; // Pour from large to small
	}
	if (SmallJug > 0 && LargeJug < largeJarMaxCapacity) {
		// Small jug can be poured into large jug
		int pourIntoLarge = min(SmallJug, largeJarMaxCapacity - LargeJug);
		vertice pourSmallToLarge = make_pair(LargeJug + pourIntoLarge, SmallJug - pourIntoLarge);
		(*potentialNeighbors)[pourSmallToLarge] = "Pour from small jug to large jug"; // Pour from small to large
	}
	if (LargeJug > 0) {
		vertice emptyLarge = make_pair(0, SmallJug);
		// Action for emptying large jug
		(*potentialNeighbors)[emptyLarge] = "Empty large jug"; ;
	}
	if (SmallJug > 0) {
		vertice emptySmall = make_pair(LargeJug, 0);
		(*potentialNeighbors)[emptySmall] = "Empty small jug";
	}

	return potentialNeighbors;
}