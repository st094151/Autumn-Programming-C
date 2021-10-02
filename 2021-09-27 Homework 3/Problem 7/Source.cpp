#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	cin >> a >> b >> c >> d;

	for (int i = 0; i <= 1000; ++i)
	{
		int result = a * i * i * i + b * i * i + c * i + d;
		if (result == 0) {
			cout << i << " ";
		}
	}

	return EXIT_SUCCESS;
}