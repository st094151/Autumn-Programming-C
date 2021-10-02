#include <iostream>
using namespace std;

int main()
{
	int x = 0;
	int result = 0;
	int square = 0;

	cin >> x;
	square = x * x;

	result = (square + x) * (square + 1) + 1;
	cout << result << endl;

	return EXIT_SUCCESS;
}