#include <iostream>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;
	cout << (n + 2 - n % 2) << endl;

	return EXIT_SUCCESS;
}