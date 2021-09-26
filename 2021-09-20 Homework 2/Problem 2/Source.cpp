#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;

	cin >> n;
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return EXIT_SUCCESS;
}