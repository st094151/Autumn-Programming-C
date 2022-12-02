#include "Edge.h"

Edge::Edge() : weight(new char[4])
{
	//std::cout << "Edge();" << std::endl;
}

Edge::Edge(double my_x1, double my_y1, double my_x2, double my_y2, int weight0, int colour0)
{
	Setx1(my_x1);
	Sety1(my_y1);
	Setx2(my_x2);
	Sety2(my_y2);

	Setweight(weight0);
	Setcolour(colour0);
	//std::cout << "Edge(double my_x1, double my_y1, double my_x2, double my_y2, int weight0, int colour0);" << std::endl;
}

Edge::~Edge()
{
	delete[] weight;
	//std::cout << "~Edge();" << std::endl;
}

void Edge::Setweight(int value)
{
	weight = new char[4];
	inttostr(value, weight);
}

void Edge::Show(HDC dc)
{
	txSetFillColor(int_to_colour(this->colour), dc);
	Line::Show(dc);
	txTextOut( (Getx1() + Getx2() + 40)/2, (Gety1() + Gety2()) / 2, weight, dc);
	txSetFillColor(TX_WHITE, dc);
}
