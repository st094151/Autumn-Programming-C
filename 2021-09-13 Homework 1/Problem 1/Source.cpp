#include <iostream>
using namespace std;
int main()
{
	int a = 0;

	cin >> a;
	cout << "The next number for the number " << a << " is " << a + 1 << "." << endl;
	cout << "The previous number for the number " << a << " is " << a - 1 << "." << endl;
	
	return EXIT_SUCCESS;
}
