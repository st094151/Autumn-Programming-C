#include "Line.h"

Line::Line()
{
	//std::cout << "Line();" << std::endl;
}

Line::Line(double my_x1, double my_y1, double my_x2, double my_y2)
{
	//std::cout << x1 << " " << y1 << " Circle(double my_x1, double my_y1, double my_x2, double my_y2);" << std::endl;
}

void Line::Show(HDC dc)
{
	txLine(this->x1, this->y1, this->x2, this->y2, dc);
}
