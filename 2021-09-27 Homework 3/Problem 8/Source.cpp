#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x = 0;
		cin >> x;
		result += x;
	}

	cout << result << endl;
	
	return EXIT_SUCCESS;
}