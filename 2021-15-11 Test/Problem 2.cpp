#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int k = 0;
	int max = 0;
	int min = 0;
	int i = 0;
	int result = 0;
	bool isfirst = true;
	bool issecond = true;

	while (cin >> k)
	{
		++i;
		if (isfirst)
		{
			min = k;
			isfirst = false;
		}

		if ((issecond) && (i == 2))
		{
			max = k;
			issecond = false;
		}


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