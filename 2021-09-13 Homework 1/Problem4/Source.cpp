#include <iostream>

using namespace std;

int main()
{
	int v = 0;
	int t = 0;
	int s = 0;

	cin >> v >> t;
	s = v * t % 109;
	s = s + 109;

	cout << s % 109 << endl;

	return EXIT_SUCCESS;
}