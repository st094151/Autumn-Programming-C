#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int mod = 0;
	int result = 0;

	cin >> a;
	cin >> b;
	c = a / b;
	d = b / a;
	result = c * b + d * a;
	mod = (a % b) % a + (b % a) % b;
	result += mod;
	result = result / (result / (a + b) + 1);
	cout << result << endl;

	return EXIT_SUCCESS;
}
