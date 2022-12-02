#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Monomial.h"

class Polynomial
{
private:
	vector<Monomial> polynom;

public:
	Polynomial();
	Polynomial(vector<int> v);
	Polynomial(const Monomial& P);
	Polynomial(const Polynomial& P);

	~Polynomial();

	vector<Monomial> getpolynom() { return polynom; };
	void setpolynom(vector<Monomial> v);

	Polynomial operator+ (const Monomial& P);
};

