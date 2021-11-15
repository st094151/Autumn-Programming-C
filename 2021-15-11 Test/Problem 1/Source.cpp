#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int k = 0;
	int n = 0;
	int m = 0;
	int result = 0;

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> n >> m;
		result = 19 * m + (n + 239) * (n + 366) / 2;
		cout << result << endl;
	}

	return EXIT_SUCCESS;
}