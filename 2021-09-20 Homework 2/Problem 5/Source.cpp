#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int k = 0;

	cin >> k;

	if ((k % 4 == 0) || (k == 1)) //  ол-во крайних клеток на доске n на n (n > 1) равно n + n + (n - 2) + (n - 2) = 4n - 4 => должно делитьс€ на 4
	{ // Ќа доске 1 на 1 кол-во крайних клеток равно 1
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return EXIT_SUCCESS;
}