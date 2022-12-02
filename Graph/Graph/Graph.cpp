#include "Graph.h"

Graph::Graph()
{
	//std::cout << "Graph();" << std::endl;
}

Graph::Graph(int n, int** matrix)
{
	setGraph_Size(n);
	setAdjacency_Matrix(matrix);
	V = new Node*[Graph_Size];

	for (int i = 0; i < Graph_Size; ++i)
	{
		V[i] = new Node(rand() % 1024, rand() % 768, i + 1, 0);
	}
}

/*
Graph::Graph(int n, int** matrix, Node value[])
{
	setGraph_Size(n);
	setAdjacency_Matrix(matrix);
	setV(value);

	//std::cout << "Graph(int n, int** matrix, Node value[]);" << std::endl;
}
*/

Graph::~Graph()
{
	Graph_Size = 0;
	delete Adjacency_Matrix;
	delete V;

	//std::cout << "~Graph();" << std::endl;
}

void Graph::setV(Node value[])
{
	V = new Node * [Graph_Size];

	for (int i = 0; i < Graph_Size; ++i)
	{
		V[i] = new Node(rand() % 1024, rand() % 768, i + 1, 0);
	}
}

void Graph::Show(HDC dc)
{
	for (int i = 0; i < Graph_Size; ++i)
	{
		V[i]->Show(dc);
	}

	for (int i = 0; i < Graph_Size; ++i)
	{
		for (int j = i; j < Graph_Size; ++j)
		{
			if (Adjacency_Matrix[i][j] != 0)
			{
				Edge* my_edge = new Edge(V[i]->Getx(), V[i]->Gety(), V[j]->Getx(), V[j]->Gety(), Adjacency_Matrix[i][j], 0);
				my_edge->Show(dc);

				delete my_edge;
			}
		}
	}
}

void Graph::Colouring()
{
	bool isFree = true;

	for (int i = 0; i < Graph_Size; ++i)
	{
		for (int k = 1; k <= Graph_Size; ++k)
		{
			isFree = true;
			for (int j = 0; j < Graph_Size; ++j)
			{
				if ( (Adjacency_Matrix[i][j] != 0) && (V[j]->Getcolour() == k) )
				{
					isFree = false;
						break;
				}
			}
			if (isFree)
			{
				V[i]->Setcolour(k);
				break;
			}
		}
		
	}
}
