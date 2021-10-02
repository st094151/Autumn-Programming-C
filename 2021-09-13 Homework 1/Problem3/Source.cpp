#include <iostream>

using namespace std;

int main()
{
	int apples = 0;
	int students = 0;

	cin >> students >> apples;
	cout << apples % students << endl;

	return EXIT_SUCCESS;
}