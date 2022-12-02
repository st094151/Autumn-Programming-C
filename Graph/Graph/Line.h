#pragma once

#include "Drawable.h"

class Line : Drawable
{
private:
	double x1;
	double x2;
	double y1;
	double y2;
public:
	Line();
	Line(double my_x1, double my_y1, double my_x2, double my_y2);
	virtual ~Line() {};
	double Getx1() { return x1; };
	void Setx1(double value) { x1 = value; };

	double Getx2() { return x2; };
	void Setx2(double value) { x2 = value; };

	double Gety1() { return y1; };
	void Sety1(double value) { y1 = value; };

	double Gety2() { return y2; };
	void Sety2(double value) { y2 = value; };

	void Show(HDC dc);
};

