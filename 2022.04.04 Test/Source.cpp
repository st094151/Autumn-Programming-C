#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, char *argv[])
{

	Fraction fr1(3, 1);
	Fraction fr2(5, -2);
	Fraction q(1, 1);
	cout << fr1 * fr2 << endl;

	cout << fr1 / fr2 << endl;
	cout << 1/(3 * fr1 + 4 * fr2) << endl;
	cout << fr1.abs() << endl; //модуль числа
	cout << fr1.reverse() << endl; //обратное число

	return EXIT_SUCCESS;
}