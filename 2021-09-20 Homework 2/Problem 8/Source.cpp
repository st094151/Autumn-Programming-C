#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a;
	cin >> b;
	cin >> c;

	if (a < b) {
		a += b; // � ���� ����������� ������� ������ ������� a � b
		b = a - b;
		a -= b;
	}
	if (c < a) { // ����� ���������� �������, ����� ���������� ����� ����� a, b, c ���� � ���������� c
		c += a;
		a = c - a;
		c -= a;
	}
	if (c >= a + b)
	{
		cout << "impossible" << endl;
	}
	else
	{
		if (c * c == b * b + a * a)
		{
			cout << "right" << endl;
		}
		else if (c * c < b * b + a * a)
		{
			cout << "acute" << endl;
		}
		else
		{
			cout << "obtuse" << endl;
		}
	}

}