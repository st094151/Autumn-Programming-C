#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int k = 0;

	cin >> k;

	if ((k % 4 == 0) || (k == 1)) // ���-�� ������� ������ �� ����� n �� n (n > 1) ����� n + n + (n - 2) + (n - 2) = 4n - 4 => ������ �������� �� 4
	{ // �� ����� 1 �� 1 ���-�� ������� ������ ����� 1
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return EXIT_SUCCESS;
}