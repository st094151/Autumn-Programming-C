#include <iostream>
#include "myLib.h"

using namespace std;

int main(int argc, char* argv[])
{
	int radius = 0;
	int n = 0;

	cin >> radius;
	cin >> n;

	circle(radius);
	cout << Collatz (n, 0);

	return EXIT_SUCCESS;
}