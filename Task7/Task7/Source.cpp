#include <iostream>
#include <vector>
#include "Monomial.h"
#include "Polynomial.h"

using namespace std;

int main()
{
	Monomial Q(15, 3);
	Monomial R(4, 5);

	vector<int> v = {15, 3, 4, 5};

/*
	vector<int> v1 = { 15, 3};
	vector<int> v2 = {4, 5 };

	Polynomial P(v1);
	Polynomial Q(v1);*/

	//Polynomial P = Q + R;
	//cout << P + Q << endl;

	return EXIT_SUCCESS;
}