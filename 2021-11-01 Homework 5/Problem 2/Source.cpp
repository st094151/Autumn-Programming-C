#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	double n = 0;
	unsigned long long value = 0;
	cin >> n;

	value = *((long long*)&n);
	cout << value << endl;

	for (int i = 0; i < sizeof(double) * 8; ++i)
	{
		unsigned long long bit = value;

		bit = bit << i;
		bit = bit >> (sizeof(double) * 8 - 1);
		cout << bit;

		if ((i + 1) % 8 == 0)
		{
			cout << " ";
		}
	}

	return EXIT_SUCCESS;
}