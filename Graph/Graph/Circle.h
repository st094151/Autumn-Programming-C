#pragma once

#include "Drawable.h"

class Circle : public Drawable
{
private:
	double x;
	double y;
	const double r = 20;
public:
	Circle();
	Circle(double x0, double y0);
	virtual ~Circle();

	double Getx() { return x; };
	double Gety() { return y; };

	void Setx(double value) { x = value; };
	void Sety(double value) { y = value; };

	void Show(HDC dc);
};

