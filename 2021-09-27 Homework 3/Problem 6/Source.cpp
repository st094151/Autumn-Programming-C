#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int negative = 0;
	int zero = 0;
	int positive = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x = 0;
		cin >> x;
		if (x < 0)
		{
			++negative;
		}
		else if (x == 0)
		{
			++zero;
		}
		else
		{
			++positive;
		}
	}

	cout << zero << " " << positive << " " << negative << endl;

	return EXIT_SUCCESS;
}