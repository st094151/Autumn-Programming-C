#pragma once
#include <iostream>
#include <cmath>

#define pi 3.145926

class Complex
{
private:
	double Re; //real part
	double Im; //imagine part

public:
	Complex(double Re = 0, double Im = 0);
	Complex(const Complex& z);
	~Complex();

	double getRe();
	void setRe(double Re);

	double getIm();
	void setIm(double Im);

	void set(double Re, double Im);

	void print();

	void sqrts(int n, std::ostream& stream);

	Complex power(int n);

	Complex Trigonometricpower(double n);

	double abs();

	double arg();

	Complex conjugate();

	Complex reverse();

	void operator= (const Complex& z);

	friend Complex operator+ (const Complex& z1, const Complex& z2);
	friend Complex operator+ (const Complex& z, const double term);
	friend Complex operator+ (const double term, const Complex& z);

	friend Complex operator* (const double mult,const Complex& z);
	friend Complex operator* (const Complex& z, const double mult);
	friend Complex operator* (const Complex& z1, const Complex& z2);

	friend Complex operator/ (const Complex& z, double denumerator);
	friend Complex operator/ (Complex& z1, Complex& z2);
	friend Complex operator/ (double denumerator, Complex& z);

	friend std::ostream& operator<<(std::ostream& stream, const Complex& complex);

};

