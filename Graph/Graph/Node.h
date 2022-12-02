#pragma once

#include "Circle.h"
/*
void inttostr (int value, char* str)
{
	int size = 0;
	int temp = value;

	while (temp != 0)
	{
		temp = temp / 10;
		++size;
	}

	if (value < 0)
	{
		str[0] = '-';
		++size;
		value = -value;
	}

	str[size] = '\0';
	while (value != 0)
	{
		str[size - 1] = value % 10;
		value = value / 10;
		--size;
	}
}
*/


class Node : public Circle
{
private:
	char* num;
	int colour;

public:
	Node();
	Node(double x0, double y0, int num0, int colour0);

	virtual ~Node();
	char* Getnum() { return num; };
	int Getcolour() { return colour; };

	void Setnum(int value);
	void Setcolour(int value) { colour = value; };

	void Show(HDC dc);
};

