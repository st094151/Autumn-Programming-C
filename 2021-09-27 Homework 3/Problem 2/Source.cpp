#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int result = 1;

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		result *= 2;
	}

	cout << result << endl;

	return EXIT_SUCCESS;
}