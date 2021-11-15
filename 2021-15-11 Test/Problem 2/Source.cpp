#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	char k = 0;
	int n = k;
	int max = 0;
	int min = 0;
	int i = 0;
	int result = 0;

	char str[200000] = { "" };

	while (k != ' \0')
	{
		cin >> k;
		n = k;
		++i;
		if (i % 2 == 0)
		{
			if (k > max)
			{
				max = k;
			}
		}
		else
		{
			if (k < min)
			{
				min = k;
			}
		}
	}

	result = max + min;
	cout << result;

	return EXIT_SUCCESS;
}