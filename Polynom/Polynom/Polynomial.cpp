#include "Polynomial.h"

Polynomial::Polynomial(vector<int> v)
{
	if (v.size() / 2 == 1)
	{
		cout << "Invalid value" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < v.size(); i = i + 2)
		{
			this->polynom.push_back(Monomial(v[i], v[i + 1]));
		}
	}
}

Polynomial::Polynomial(const Monomial& P)
{
	this->polynom.push_back(P);
}

Polynomial::Polynomial(const Polynomial& P)
{
	for (unsigned int i = 0; i < P.polynom.size(); ++i)
	{
		Monomial temp = P.polynom[i];
		this->polynom.push_back(temp);
	}
}
		
Polynomial::~Polynomial()
{
	this->polynom.clear();
}

void Polynomial::setpolynom(vector<Monomial> v)
{
	this->polynom = v;
}

Polynomial Polynomial::operator+(const Monomial& P)
{

	return Polynomial();
}
