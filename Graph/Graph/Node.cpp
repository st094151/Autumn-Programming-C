#include "Node.h"

Node::Node() : num (new char[4])
{
	//std::cout << "Node();" << std::endl;
}

Node::Node(double x0, double y0, int num0, int colour0)
{
	Setx(x0);
	Sety(y0);
	Setnum(num0);
	Setcolour(colour0);
	//std::cout << Getx() << "Node(double x0, double y0, int num0);" << std::endl;
}

Node::~Node()
{
	delete[] num;
	//std::cout << Getx() << "~Node();" << std::endl;
}

void Node::Setnum(int value)
{
	num = new char[4];
	inttostr(value, num);
}

void Node::Show(HDC dc)
{
	txSetFillColor(int_to_colour(this->colour), dc);
	Circle::Show(dc);
	txTextOut((Getx() + 30), Gety(), Getnum(), dc);
	txSetFillColor(TX_WHITE, dc);
	//txTextOut(this->x, this->y, this->num, txDC());
}