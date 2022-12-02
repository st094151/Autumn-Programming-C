#include "Circle.h"

Circle::Circle()
{
	//std::cout << "Circle();" << std::endl;
}

Circle::Circle(double x0, double y0) : x(x0), y(y0)
{
	//std::cout << x << " " << y << " Circle(double x0, double y0);" << std::endl;
}

Circle::~Circle()
{
	//std::cout << x << " ~Circle();" << std::endl;
}

void Circle::Show(HDC dc)
{
	txEllipse(x - r, y - r, x + r, y + r, dc);
}
