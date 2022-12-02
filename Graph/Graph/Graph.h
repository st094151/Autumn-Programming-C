#pragma once

#include "Node.h"
#include "Edge.h"

class Graph
{
private:
	int Graph_Size;
	int** Adjacency_Matrix;
	Node** V;

public:
	Graph();
	Graph(int n, int** matrix);

	int getGraph_Size() { return Graph_Size; };
	int** getAdjacency_Matrix() { return Adjacency_Matrix; };
	Node** getV() { return V; };

	virtual ~Graph();

	void setGraph_Size(int n) { Graph_Size = n; };
	void setAdjacency_Matrix(int** value) { Adjacency_Matrix = value; };
	void setV(Node value[]);

	void Show(HDC dc);

	void Colouring();
};

