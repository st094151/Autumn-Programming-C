#pragma once

#include "Line.h"

class Edge : public Line
{
private:
	char* weight;
	int colour;

public:
	Edge();
	Edge(double my_x1, double my_y1, double my_x2, double my_y2, int weight0, int colour0);

	virtual ~Edge();
	char* Getweight() { return weight; };
	int Getcolour() { return colour; };

	void Setweight(int value);
	void Setcolour(int value) { colour = value; };

	void Show(HDC dc);
};

