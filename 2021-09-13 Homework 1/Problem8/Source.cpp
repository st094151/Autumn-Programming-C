#include <iostream>
using namespace std;

int main()
{
	int h1 = 0;
	int h2 = 0;
	int min1 = 0;
	int min2 = 0;
	int sec1 = 0;
	int sec2 = 0;
	int result = 0;

	cin >> h1 >> min1 >> sec1;
	cin >> h2 >> min2 >> sec2;
	result = (h2 - h1) * 3600 + (min2 - min1) * 60 + (sec2 - sec1);
	cout << result << endl;

	return EXIT_SUCCESS;
}