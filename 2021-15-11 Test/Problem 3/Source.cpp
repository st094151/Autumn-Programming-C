#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int a0 = 0;
	int b0 = 0;
	int LCM = 0;

	cin >> a >> b;

	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	a0 = a;
	b0 = b;

	while (a % b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	LCM = (a0 * b0) / b;

	cout << LCM;

	return EXIT_SUCCESS;
}