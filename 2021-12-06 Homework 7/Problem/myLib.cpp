#include <iostream>
#include "myLib.h"

using namespace std;

int Collatz(int n, int result)
{
	if (n == 1)
	{
		return result;
	}
	else if (n % 2 == 0)
	{
		Collatz(n / 2, result + 1);
	}
	else
	{
		Collatz((3 * n + 1), result + 1);
	}
}

void circle(int r)
{

	if (r == 0)
	{
		cout << "*";
		return;
	}

	for (int i = 0; i <= 2 * r; ++i)
	{
		int j = 0;

		while ((r - i) * (r - i) + (r - j) * (r - j) > r * r)
		{
			++j;
			cout << " ";
		}
		cout << "*";

		while (j != r)
		{
			++j;
			cout << " ";
		}

		while ((r - i) * (r - i) + (r - j) * (r - j) <= r * r)
		{
			++j;
			cout << " ";
		}
		cout << "*" << endl;
	}
}