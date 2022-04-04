#pragma once
#include <iostream>

class Fraction
{
	private:
		long long numerator;
		long long denominator;

	public:
		Fraction(long long numerator = 0, long long denominator = 1);
		Fraction(const Fraction& q);
		~Fraction();

		long long getnumerator();
		void setnumerator(long long numerator);

		long long getdenominator();
		void setdenominator(long long denominator);

		void set(long long numerator, long long denominator);

		long long LCM();// Least common multiple == ÍÎÊ

		Fraction reducted();

		Fraction reverse();

		Fraction abs();
		Fraction power(int n);

		void operator= (const Fraction& q);
		
		bool operator== (Fraction& q);
		
		bool operator> (Fraction& q);
		bool operator>= (Fraction& q);

		bool operator< (Fraction& q);
		bool operator<= (Fraction& q);

		friend Fraction operator+ (const Fraction& q1, const Fraction& q2);
		friend Fraction operator+ (const long long n, const Fraction& q);
		friend Fraction operator+ (const Fraction& q, const long long n);

		friend Fraction operator* (const Fraction& q1, const Fraction& q2);
		friend Fraction operator* (const Fraction& q, const long long n);
		friend Fraction operator* (const long long n, const Fraction& q);

		friend Fraction operator- (const Fraction& q1, const Fraction& q2);
		friend Fraction operator- (const long long n, const Fraction& q);
		friend Fraction operator- (const Fraction& q, const long long n);

		friend Fraction operator/ (Fraction& q1, Fraction& q2);
		friend Fraction operator/ (Fraction& q, long long n);
		friend Fraction operator/ (const long long n, Fraction q);

		friend std::ostream& operator<<(std::ostream& stream, const Fraction& q);




};

