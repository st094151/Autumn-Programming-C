#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int a[1000] = { 0 };
	int min = 0;
	int max = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	min = a[0];
	max = a[0];

	for (int i = 0; i < n; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == max)
		{
			a[i] = min;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return EXIT_SUCCESS;
}