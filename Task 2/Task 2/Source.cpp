#include <iostream>
#include <array>

using namespace std;

const int n = 100;
int Sign(array<int, n> a, int k)
{
	if (k == 0)
	{
		return 0;
	}

	int result = 0;
	int signum = 0;

	if (a[0] < 0)
	{
		signum = 1;
	}

	for (int i = 1; i < k; ++i)
	{

	}
}

int main()
{
	

	array <int, n> a;
	int k = 0;

	cout << "Print number of elements" << endl;
	cin >> k;

	cout << "Print number elements of array" << endl;

	if (k > n)
	{
		cout << "Invalid input" << endl;
	}
	else
	{
		for (int i = 0; i < k; ++i)
		{
			cin >> a[i];
		}
	}

	
}