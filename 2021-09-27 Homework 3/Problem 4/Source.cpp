#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;
	int max = 0;
	int result = 1;

	cin >> n >> k;
	
	max = k;
	if (n - k > max)
	{
		max = n - k;
	}

	for (int i = max + 1; i <= n; ++i)
	{
		result *= i;
	}

	for (int i = 1; i <= n - max; ++i)
	{
		result /= i;
	}

	cout << result;

	return EXIT_SUCCESS;
}