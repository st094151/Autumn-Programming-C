#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int result = 0;

	cin >> n;
	result = (n % 10 + (n/10) % 10 + (n/100));
	cout << result << endl;

	return EXIT_SUCCESS;
}