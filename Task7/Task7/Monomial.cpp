#include "Monomial.h"

Monomial::Monomial(int coefficient, int power)
{
	setcoefficient(coefficient);
	setpower(power);
}

Monomial::Monomial(const Monomial& P)
{
	setcoefficient(P.coefficient);
	setpower(P.power);
}

Monomial::~Monomial()
{
	this->coefficient = 0;
	this->power = 0;
}

int Monomial::getcoefficient()
{
	return this->coefficient;
}

void Monomial::setcoefficient(int c)
{
	this->coefficient = c;
}

int Monomial::getpower()
{
	return this->power;
}

void Monomial::setpower(int n)
{
	this->power = n;
}

void Monomial::operator=(const Monomial& P)
{
	this->coefficient = P.coefficient;
	this->power = P.power;
}

bool Monomial::operator<(const Monomial& P)
{
	return this->power < P.power;
}

bool Monomial::operator<=(const Monomial& P)
{
	return this->power <= P.power;
}

bool Monomial::operator>(const Monomial& P)
{
	return this->power > P.power;
}

bool Monomial::operator>=(const Monomial& P)
{
	return this->power >= P.power;
}

Monomial Monomial::operator+(const Monomial& P)
{
	if (this->power == P.power)
	{
		return Monomial(this->coefficient + P.coefficient, this->power);
	}
	else
	{
		return P;
	}
}

Monomial Monomial::operator-(const Monomial& P)
{
	if (this->power == P.power)
	{
		return Monomial(this->coefficient - P.coefficient, this->power);
	}
	else
	{
		return P;
	}
}

Monomial Monomial::operator*(const Monomial& P)
{
	return Monomial(this->coefficient * P.coefficient, this->power + P.power);
}
		 
Monomial Monomial::operator*(const int k)
{
	return Monomial(this->coefficient * k, this->power);
}

/*
Monomial Monomial::operator*(const int k, const Monomial& P)
{
	return Monomial(P.coefficient * k, P.power);
}
*/

std::ostream& Monomial::operator<<(std::ostream& stream)
{
	stream << this->coefficient << "x^" << this->power;

	return stream;
}
