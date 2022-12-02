#include "Monomial.h"

Monomial::Monomial(int coefficient, int power)
{
	this->coefficient = coefficient;
	this->power = power;
}

Monomial::Monomial(const Monomial& P)
{
	this->coefficient = P.coefficient;
	this->power = P.power;
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
	if (this->power < P.power)
	{
		return true;
	}

	return false;
}

bool Monomial::operator<=(const Monomial& P)
{
	if (this->power <= P.power)
	{
		return true;
	}

	return false;
}

bool Monomial::operator>(const Monomial& P)
{
	if (this->power > P.power)
	{
		return true;
	}

	return false;
}

bool Monomial::operator>=(const Monomial& P)
{
	if (this->power >= P.power)
	{
		return true;
	}

	return false;
}

Monomial Monomial::operator+(const Monomial& P)
{
	if (this->power == P.power)
	{
		return Monomial(this->coefficient + P.coefficient, this->power);
	}
	else
	{
		return Monomial(P);
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
		return Monomial(P.coefficient * (-1), P.power);
	}
}

Monomial Monomial::operator*(const Monomial& P)
{
	if ((this->coefficient == 0) || (P.coefficient == 0) )
	{
		return Monomial (0, 0);
	}
	else
	{
		return Monomial(this->coefficient * P.coefficient, this->power + P.power);
	}
}

Monomial Monomial::operator*(const int k)
{
	if (k != 0)
	{
		return Monomial(this->coefficient * k, this->power);
	}
	else
	{
		return Monomial(0, 0);
	}
	
}

Monomial operator*(const int k, const Monomial& P)
{
	if (k != 0)
	{
		return Monomial(k * P.coefficient, P.power);
	}
	else
	{
		return Monomial(0, 0);
	}
	
}

ostream& operator<<(ostream& stream, const Monomial& P)
{
	Monomial Q(P);
	if (Q.getpower() != 0)
	{
		stream << Q.getcoefficient() << "x^" << Q.getpower();
	}
	else
	{
		stream << Q.getcoefficient();
	}
	
	return stream;
}
