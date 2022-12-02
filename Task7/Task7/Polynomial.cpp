#include "Polynomial.h"

using namespace std;

bool CompMonomial(Monomial P1, Monomial P2)
{
	return P1.getpower() < P2.getpower();
}


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
			this->polynom.push_back(new Monomial(v[i], v[i + 1]));
		}
	}
}

Polynomial::Polynomial(const Polynomial& P)
{
	for (unsigned int i = 0; i < P.polynom.size(); ++i)
	{
		this->polynom.push_back(new Monomial(P.polynom[i]->getcoefficient(), P.polynom[i]->getpower()));
	}
}

Polynomial::~Polynomial()
{
	this->polynom.clear();
}

void Polynomial::setpolynom(vector<Monomial*> P)
{
	this->polynom = P;
}

void Polynomial::pushback(const Monomial& P)
{
	this->getpolynom().push_back(new Monomial(P));
}

Polynomial Polynomial::operator+(const Monomial& P)
{
	/*
	//vector<int> v ={};
	Monomial Q1(P1);
	Monomial Q2(P2);
	Polynomial P;
	
	if (Q1.getpower() == Q2.getpower())
	{
		/*v.push_back(Q1.getcoefficient() + Q2.getcoefficient());
		v.push_back(Q1.getpower());

		Polynomial* P = new Polynomial(v);
		sort(P->getpolynom().begin(), P->getpolynom().end());
		
		Q1.setcoefficient(Q1.getcoefficient() + Q2.getcoefficient());
		P.pushback(Q1);

		return P;
	}
	else
	{
		P.pushback(Q1);
		P.pushback(Q2);
		sort(P.getpolynom().begin(), P.getpolynom().end());
		//qsort(&P->getpolynom()[0], P->getpolynom().size(), sizeof(Monomial));

		return P;
	}
	*/

	//iterator it = this->polynom.begin();
	/*
	vector<Monomial*>::iterator it = this->polynom.begin();

	for (unsigned int i = 0; i < this->polynom.size(); ++i)
	{

	}*/

	Polynomial P1;
	return P1;
}

std::ostream& operator<<(std::ostream& stream, const Polynomial& P)
{
	//vector<Monomial*>::iterator it = P.polynom.begin();

	//stream << monom.coefficient << "x^" << monom.power;

	return stream;
}
