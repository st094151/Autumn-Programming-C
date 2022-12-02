#include <iostream>
#include <vector>
#include <algorithm>
#include "Monomial.h"
#include "Polynomial.h"

using namespace std;

int main()
{
	Monomial P(15, 3);
	Monomial Q(2, 10);

	vector<int> v = { 15, 3, 16, 4 };

	Polynomial R(P);
	
	cout << R.getpolynom()[0] << endl;

	P = P * 2;
/*
	cout << "P = " << P << endl;
	cout << "R = " << R.getpolynom()[0] << endl;

	Polynomial G(R);

	cout << "G = " << G.getpolynom()[0] << endl;*/

	vector<Monomial> v1;
	v1.push_back(P);
	v1.push_back(Q);

	R.setpolynom(v1);

	cout << "R = " << R.getpolynom()[0] << " + " << R.getpolynom()[1] << endl;

	return EXIT_SUCCESS;
}