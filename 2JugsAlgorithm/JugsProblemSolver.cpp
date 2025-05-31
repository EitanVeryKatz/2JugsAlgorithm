#include "JugsProblemSolver.h"

void JugsProblemSolver::Solve(int i_wantedAmountInLargeJar) {

	// Solve the jugs problem using BFS
	auto startTimer = chrono::high_resolution_clock::now();

	vertice start = make_pair(0, 0); // Starting state (both jugs empty)
	vertice goal = make_pair(i_wantedAmountInLargeJar, 0); // Goal state (large jug has W liters, small jug is empty)

	int numbeOfOperationsNeeded = BFS(&start, &goal); // Get the distance to the goal

	auto stopCounter = chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopCounter - startTimer);

	if (numbeOfOperationsNeeded == INFINITY) {
		std::cout << "No solution." << endl;
	}
	else {
		// Reconstruct the path from start to goal
		list<string> operationSequence;
		vertice current = goal;
		int operationCount = 1; // Start counting operations from 1

		while (current != start) {
			operationSequence.push_front(parent[current].second);
			current = parent[current].first; // Move to parent
		}

		std::cout << "Number of operations: " << numbeOfOperationsNeeded << "\n";
		std::cout << "Operations: " << endl;
		for (const auto& operation : operationSequence) {
			cout << operationCount++ << ". ";
			cout << operation << endl;
		}
	}

	if (runTimeWanted) {
		std::cout << "Function took " << duration.count() << " microseconds." << std::endl;
	}

	std::cout << "\n";

}

map <vertice, string>* JugsProblemSolver::CalculateAdjList(vertice i__TargetVertice,int i_SmallJarMaxCapacity,int i_LargeJarMaxCapacity)
{

	int LargeJug = i__TargetVertice.first;
	int SmallJug = i__TargetVertice.second;

	map<vertice, string>* potentialNeighbors = new map<vertice, string>;

	if (LargeJug > 0) {
		vertice emptyLarge = make_pair(0, SmallJug);
		// Action for emptying large jug
		(*potentialNeighbors)[emptyLarge] = "Empty large jug"; ;
	}

	if (LargeJug > 0 && SmallJug < i_SmallJarMaxCapacity) {
		// Large jug can be poured into small jug
		int pourIntoSmall = min(LargeJug, i_SmallJarMaxCapacity - SmallJug);
		vertice pourLargeToSmall = make_pair(LargeJug - pourIntoSmall, SmallJug + pourIntoSmall);
		(*potentialNeighbors)[pourLargeToSmall] = "Pour from large jug to small jug"; // Pour from large to small
	}

	if (SmallJug > 0) {
		vertice emptySmall = make_pair(LargeJug, 0);
		(*potentialNeighbors)[emptySmall] = "Empty small jug";
	}

	if (SmallJug > 0 && LargeJug < i_LargeJarMaxCapacity) {
		// Small jug can be poured into large jug
		int pourIntoLarge = min(SmallJug, i_LargeJarMaxCapacity - LargeJug);
		vertice pourSmallToLarge = make_pair(LargeJug + pourIntoLarge, SmallJug - pourIntoLarge);
		(*potentialNeighbors)[pourSmallToLarge] = "Pour from small jug to large jug"; // Pour from small to large
	}

	if (SmallJug < i_SmallJarMaxCapacity) {

		vertice fillSmall = make_pair(LargeJug, i_SmallJarMaxCapacity);// Fill small jug
		(*potentialNeighbors)[fillSmall] = "Fill small jug"; // Action for filling small jug
	}

	if (LargeJug < i_LargeJarMaxCapacity) {
		vertice fillLarge = make_pair(i_LargeJarMaxCapacity, SmallJug);// Fill large jug
		(*potentialNeighbors)[fillLarge] = "Fill large jug";
	}

	return potentialNeighbors;
}