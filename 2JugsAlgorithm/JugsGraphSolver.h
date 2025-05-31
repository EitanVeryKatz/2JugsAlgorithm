#pragma once
#include "JugsProblemSolver.h"

class JugsGraphSolver:public JugsProblemSolver
{
private:
	map <vertice, list <edge*> > m_VerticesAdjList; // Adjacency list representation

	void MakeEmptyGraph(int i_LargeJugMaxCapacity, int i_SmallJugMaxCapacity);
	void AddEdge(vertice i_sourceVertice, vertice i_DestinationVertice,string i_actionDescription);
	void SetUpVEdgesForJugs(int i_LargeJugMaxCapacity, int i_SmallJugMaxCapacity);
	int BFS(vertice* i_Start, vertice* i_Goal) override;
	list <edge*> GetAdjList(vertice i_TargetVertice);

public:
	JugsGraphSolver(int i_LargeJugMaxCapacity,int i_SmallJugMaxCapacity, int i_isRuntimeWanted)
	{
		runTimeWanted = i_isRuntimeWanted;
		MakeEmptyGraph(i_LargeJugMaxCapacity,i_SmallJugMaxCapacity); // Initialize the graph with vertices based on jug capacitiesl
		SetUpVEdgesForJugs(i_LargeJugMaxCapacity, i_SmallJugMaxCapacity);
	}

	~JugsGraphSolver()
	{
		for (auto& vertice : m_VerticesAdjList)
		{
			for (auto& neighbor : vertice.second)
			{
				 // Free the vertice (state) itself
				delete neighbor; // Free the edge itself

			}
		}
	}

};

