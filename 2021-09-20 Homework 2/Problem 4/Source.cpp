#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int x1 = 0; // �������� x ��� ax + b = 0
	int x2 = 0; // �������� x ��� cx + d = 0

	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	if (a != 0) // ��������, ����� �������� ������� �� 0
	{
		if (b % a == 0) // � ���� ������ ���������� ������������� ������ x1
		{
			x1 = (-1) * (b / a);
		}
	}
	
	if (c != 0) // ��������, ����� �������� ������� �� 0
	{
		if (d % c == 0) // � ���� ������ x2 ����� �������������
		{
			x2 = (-1) * (d / c);
		}
		else
		{
			x2 = x1 + 1;// ��������� �������, ����� �� �������� ������ x1 = 0, �.�. x2 - �� ����� � � ������ ������ x2 = 0
		}
	}

	if ((a == 0) && (b == 0)) // � ��������� �������� 0
	{
		cout << "INF" << endl;
	}
	else if (x1 == x2) // ��������� � ����������� ����� ����� ������
	{
		cout << "NO" << endl;
	}
	else if (a != 0) //��������, ����� �������� ������� �� 0
	{
		if (b % a == 0) // �������� ������ � ��������� ��� ������������� ������, � � ����������� ������ �� ���������
		{
			cout << x1 << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}

	return EXIT_SUCCESS;
}