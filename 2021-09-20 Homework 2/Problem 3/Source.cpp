#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int k = 0; //���������� ������, ������� ����� ���������� ������������
	int m = 0; //����� �� ������� ����� �������
	int n = 0; //���������� ������, ������� ���������� ��������
	int result = 0;

	cin >> k;//f
	cin >> m;
	cin >> n;

	if (n > k) {
		result = 2 * n / k;
		if (2 * n % k != 0) {
			result++;
		}
	}
	else
	{
		result = 2;
	}

	result *= m;
	cout << result << endl;

	return EXIT_SUCCESS;
}