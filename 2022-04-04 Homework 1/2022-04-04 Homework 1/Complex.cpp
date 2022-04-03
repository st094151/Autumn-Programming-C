#include "Complex.h"

Complex::Complex(double Re, double Im) : Re(Re), Im(Im){}

Complex::Complex(const Complex& z) : Re(z.Re), Im(z.Im){}

Complex::~Complex()
{
	this->Re = 0;
	this->Im = 0;
}

double Complex::getRe()
{
	return this->Re;
}

void Complex::setRe(double Re)
{
	this->Re = Re;
}

double Complex::getIm()
{
	return this->Im;
}

void Complex::setIm(double Im)
{
	this->Im = Im;
}

void Complex::set(double Re, double Im)
{
	this->Re = Re;
	this->Im = Im;
}

void Complex::print()
{
	if (this->Re == 0)
	{
		if (this->Im == 1)
		{
			std::cout << "i" << std::endl;
		}
		else if (this->Im == -1)
		{
			std::cout << "-i" << std::endl;
		}
		else if (this->Im == 0)
		{
			std::cout << "0" << std::endl;
		}
		else
		{
			std::cout << this->Im << "i" << std::endl;
		}
	}
	else if (this->Im == 0)
	{
		std::cout << this->Re << std::endl;
	}
	else
	{
		if (this->Im == 1)
		{
			std::cout << this->Re << "+" << "i" << std::endl;
		}
		else if (this->Im == -1)
		{
			std::cout << this->Re << "-" << "i" << std::endl;
		}
		else if (this->Im < 0)
		{
			std::cout << this->Re << this->Im << "i" << std::endl;
		}
		else
		{
			std::cout <<this->Re << "+" << this->Im << "i" << std::endl;
		}
		
	}
	 
}

void Complex::sqrts(int n, std::ostream& stream)
{
	Complex z(0, 0);

	for (int j = 0; j < n; j++)
	{
		z.setRe(cos((this->arg()) / n + j * (2 * pi) / n));
		z.setIm(sin((this->arg()) / n + j * (2 * pi) / n));
		z = z * pow(this->abs(), 1 / n);
		stream << z << " ";
	}
}

Complex Complex::power(int n)
{
	Complex z(this->Re, this->Im);
	Complex result(this->Re, this->Im);

	for (int i = 0; i < n - 1; i++)
	{
		result = result * z;
	}

	return result;
}

Complex Complex::Trigonometricpower(double n)
{
	return Complex(cos(n * this->arg()) * (pow(this->abs(), n)), sin(n * this->arg()) * (pow(this->abs(), n)));
}

double Complex::abs()
{
	return sqrt((this->Re * this->Re + this->Im * this-> Im));
}

double Complex::arg()
{
	if (this->abs() == 0)
	{
		return 0;
	}
	else if (this->Im < 0)
	{
		return (2 * pi - acos(this->Re / this->abs()));
	}
	return acos (this->Re / this->abs());
}

Complex Complex::conjugate()
{
	return Complex(this->Re, this->Im * (-1));
}

Complex Complex::reverse()
{
	return this->conjugate() / (this->Re * this->Re + this->Im * this->Im);
}

void Complex::operator=(const Complex& z)
{
	this->Re = z.Re;
	this->Im = z.Im;
}

Complex operator+(const Complex& z1, const Complex& z2)
{
	return Complex(z1.Re + z2.Re, z1.Im + z2.Im);
}

Complex operator+(const Complex& z, const double term)
{
	return Complex(z.Re + term, z.Im);
}

Complex operator+(const double term, const Complex& z)
{
	return Complex(z.Re + term, z.Im);
}

Complex operator*(const double mult, const Complex& z)
{
	return Complex(z.Re * mult, z.Im * mult);
}

Complex operator*(const Complex& z, const double mult)
{
	return Complex(z.Re * mult, z.Im * mult);
}

Complex operator*(const Complex& z1, const Complex& z2)
{
	return Complex(z1.Re * z2.Re - z1.Im * z2.Im, z1.Re * z2.Im + z1.Im * z2.Re);
}

Complex operator/(const Complex& z, double denumerator)
{
	return Complex(z.Re / denumerator, z.Im / denumerator);
}

Complex operator/(Complex& z1, Complex& z2)
{
	return Complex(z1 * z2.reverse());
}

Complex operator/(double denumerator, Complex& z)
{
	return Complex(denumerator * z.reverse());
}

std::ostream& operator<<(std::ostream& stream, const Complex& complex)
{
	if (complex.Re == 0)
	{
		if (complex.Im == 1)
		{
			stream << "i";
		}
		else if (complex.Im == -1)
		{
			stream << "-i";
		}
		else if (complex.Im == 0)
		{
			stream << "0";
		}
		else
		{
			stream << complex.Im << "i";
		}
	}
	else if (complex.Im == 0)
	{
		stream << complex.Re;
	}
	else
	{
		if (complex.Im == 1)
		{
			stream << complex.Re << "+" << "i";
		}
		else if (complex.Im == -1)
		{
			stream << complex.Re << "-" << "i";
		}
		else if (complex.Im < 0)
		{
			stream << complex.Re << complex.Im << "i";
		}
		else
		{
			stream << complex.Re << "+" << complex.Im << "i";
		}

	}

	return stream;
}