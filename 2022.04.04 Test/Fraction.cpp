#include "Fraction.h"

long long Euclid(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return Euclid(b, a % b);
	}

}

Fraction::Fraction(long long numerator, long long denominator) : numerator(numerator), denominator(denominator){}

Fraction::Fraction(const Fraction& q) : numerator(q.numerator), denominator(q.denominator){}

Fraction::~Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}

long long Fraction::getnumerator()
{
	return this->numerator;
}

void Fraction::setnumerator(long long numerator)
{
	this->numerator = numerator;
}

long long Fraction::getdenominator()
{
	return this->denominator;
}

void Fraction::setdenominator(long long denominator)
{
	this->denominator = denominator;
}

void Fraction::set(long long numerator, long long denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

long long Fraction::LCM() // Greatest common divisor == ÍÎÊ
{
	return ((this->numerator * this->denominator) / Euclid(this->numerator, this->denominator));
}

Fraction Fraction::reducted()
{
	return Fraction((this->numerator) / Euclid(this->numerator, this->denominator), (this->denominator) / Euclid(this->numerator, this->denominator));
}

Fraction Fraction::reverse()
{
	Fraction q(this->denominator, this->numerator);
	return q.reducted();
}

Fraction Fraction::abs()
{
	if ((this->numerator < 0) && (this->denominator < 0))
	{
		return Fraction((-1) * this->numerator, (-1) * this->denominator);
	}
	else if (this->numerator < 0)
	{
		return Fraction((-1) * this->numerator, this->denominator);
	}
	else if (this->denominator < 0)
	{
		return Fraction(this->numerator, (-1) * this->denominator);
	}
	else
	{
		return Fraction(this->numerator, this->denominator);
	}	
}

Fraction Fraction::power(int n)
{
	Fraction q(this->numerator, this->denominator);
	if (n > 0)
	{
		for (int i = 0; i < n - 1; i++)
		{
			q.setnumerator(q.getnumerator() * this->numerator);
			q.setdenominator(q.getdenominator() * this->denominator);
		}
		return (q.reducted());
	}
	else
	{
		n = n * (-1);
		for (int i = 0; i < n - 1; i++)
		{
			q.setnumerator(q.getnumerator() * this->numerator);
			q.setdenominator(q.getdenominator() * this->denominator);
		}
		return q.reverse();
	}

}

void Fraction::operator=(const Fraction& q)
{
	this->numerator = q.numerator;
	this->denominator = q.denominator;
}

bool Fraction::operator==(Fraction& q)
{
	if ((this->LCM() / Euclid(this->numerator, this->denominator)) == (q.LCM() / Euclid(q.numerator, q.denominator)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator>(Fraction& q)
{
	if ( (this->numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator))/this->denominator) > (q.numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / q.denominator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator>=(Fraction& q)
{
	if ((this->numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / this->denominator) >= (q.numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / q.denominator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator<(Fraction& q)
{
	if ((this->numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / this->denominator) < (q.numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / q.denominator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator<=(Fraction& q)
{
	if ((this->numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / this->denominator) <= (q.numerator * ((this->denominator * q.denominator) / Euclid(this->denominator, q.denominator)) / q.denominator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Fraction operator+(const Fraction& q1, const Fraction& q2)
{
	Fraction q((q1.numerator * q2.denominator) + (q2.numerator * q1.denominator), q1.denominator * q2.denominator);
	return q.reducted();
}

Fraction operator+(const long long n, const Fraction& q)
{
	Fraction q1(n, 1);
	return (q + q1);
}

Fraction operator+(const Fraction& q, const long long n)
{
	Fraction q1(n, 1);
	return (q + q1);
}

Fraction operator*(const Fraction& q1, const Fraction& q2)
{
	Fraction q(q1.numerator * q2.numerator, q1.denominator * q2.denominator);
	return (q.reducted());
}

Fraction operator*(const Fraction& q, const long long n)
{
	Fraction q1(n, 1);
	return (q * q1);
}

Fraction operator*(const long long n, const Fraction& q)
{
	Fraction q1(n, 1);
	return (q * q1);
}

Fraction operator-(const Fraction& q1, const Fraction& q2)
{
	return (q1 + (-1) * q2);
}

Fraction operator-(const long long n, const Fraction& q)
{
	return (n * (-1) + q);
}

Fraction operator-(const Fraction& q, const long long n)
{
	return (q + n * (-1));
}

Fraction operator/(Fraction& q1, Fraction& q2)
{
	Fraction q(q1.getnumerator() * q2.getdenominator(), q1.getdenominator() * q2.getnumerator());
	return (q.reducted());
}

Fraction operator/(Fraction& q, long long n)
{
	Fraction q1(q.numerator, q.denominator * n);
	return q1.reducted();
}

Fraction operator/(const long long n, Fraction q)
{
	return Fraction(n * q.getdenominator(), q.getnumerator());
}

std::ostream& operator<<(std::ostream& stream, const Fraction& q)
{
	Fraction q1(q.numerator, q.denominator);

	q1 = q1.reducted();

	stream << q.numerator <<  "/" << q.denominator <<  std::endl;

	return stream;
}

