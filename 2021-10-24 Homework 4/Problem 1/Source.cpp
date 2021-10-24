#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int sum = 0;// ����� ��������� �������
	bool containnegative = false; //���������� �� ������������� �������� � �������
	int negativeproduct = 1;// ������������ ������������� ���������
	int min = 0;
	int max = 0;
	int premax = 0; //������ �� �������� �������
	const int maxlength = 100;
	int a[maxlength] = { 0 };

	cin >> n;

	//���������� �������
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	//����� �������
	cout << "ARRAY : ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	//����� ������ ��������� �������
	cout << "EVEN : ";
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i] << ' ';
		}
	}
	cout << endl;

	// ����� ��������� �������
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	cout << "SUM : " << sum << endl;

	//������������ ������������� ��������� �������
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < 0)
		{
			containnegative = true;
			negativeproduct *= a[i];
		}
	}
	cout << "PRODUCT OF NEGATIVE : ";
	if (containnegative)
	{
		cout << negativeproduct;
	}
	cout << endl;

	//������ ������� ������������ ��������
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < a [min])
		{
			min = i;
		}
	}
	cout << "FIRST MIN INDEX : " << min << endl;

	//������ �� �������� ��������
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= a[max])
		{
			premax = max;
			max = i;
		}
		else if ( (a[i] >= a[premax]) || (max == premax) )//������ ������ �� ������, ����� ������ ������� ������������
		{
			premax = i;
		}
	}
	cout << "SECOND MAX : " << a[premax] << endl;

	//����� ������� � �������� �������
	cout << "REVERSE : ";
	for (int i = n - 1; i >= 0; --i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	//����� �������� ������� � ��������� ���������
	cout << "ODD INDEXES : ";
	for (int i = 1; i < n - (n % 2); i += 2)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	return EXIT_SUCCESS;
}