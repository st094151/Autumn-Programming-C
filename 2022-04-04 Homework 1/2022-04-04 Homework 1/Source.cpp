#include <iostream>;
#include "Complex.h"

using namespace std;

int main()
{
	Complex z1(3, 1);
	Complex z2(5, -2);

	cout << z1 * z2 << endl;
	cout << z1 / z2 << endl;
	cout << 3 * z1 + 4 * z2 << endl;
	cout << z1.abs() << endl; //модуль числа
	cout << z1.arg() << endl; //аргумент числа
	cout << z1.reverse() << endl; //обратное число
	z1.sqrts(5, cout); //вывод в поток cout формулы корней пятой степени

	return EXIT_SUCCESS;
}