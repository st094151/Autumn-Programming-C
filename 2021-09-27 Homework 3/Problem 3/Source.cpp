#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int c = 1; // —четчик дл€ длины строки
	int i = 1;
	int j = 0;

	cin >> n;

	while (i <= n)
	{
		while (j < c)
		{
			cout << i << " ";
			++j;
			++i;
			if (i == n + 1)
			{
				break;
			}
		}
		++c;
		j = 0;
		cout << endl;
		if (i == n + 1)
		{
			break;
		}
	}

	return EXIT_SUCCESS;
}