#pragma once
#include <iostream>
#include <algorithm>

class Monomial
{
private:
	int coefficient;
	int power;

public:
	Monomial(int coefficient = 0, int power = 0);
	Monomial(const Monomial& P);
	~Monomial();

	int getcoefficient();
	void setcoefficient(int c);

	int getpower();
	void setpower(int n);
	
	void operator= (const Monomial& P);

	bool operator< (const Monomial& P);
	bool operator<= (const Monomial& P);
	bool operator> (const Monomial& P);
	bool operator>= (const Monomial& P);

	Monomial operator+ (const Monomial& P);

	Monomial operator- (const Monomial& P);

	Monomial operator* (const Monomial& P);
	Monomial operator* (const int k);
	//Monomial operator* (const Monomial& P, const int k);
	
	std::ostream& operator<< (std::ostream& stream);
};

