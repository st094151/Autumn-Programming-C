#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Monomial.h"

using namespace std;

class Polynomial 
{
private:
	vector<Monomial*> polynom;


public:
	Polynomial();
	Polynomial(vector<int> v);
	Polynomial(const Polynomial& P);

	~Polynomial();

	vector<Monomial*> getpolynom() { return polynom; };

	void setpolynom(vector<Monomial*> P);

	void pushback(const Monomial& P);

	Polynomial operator+ ( const Monomial& P);

	friend std::ostream& operator<< (std::ostream& stream, const Polynomial& P);
};

