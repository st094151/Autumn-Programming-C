#include <iostream>
#include <clocale>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	int n = 0;
	int a = 0;// �����
	int b = 0;// �������
	int c = 0;// �������

	cin >> n;
	c = n % 10;
	b = ((n - c) % 100) / 10;
	a = ((n - b - c) % 1000) / 100;

	switch (a)
	{
	case 1:
		cout << "��� ";
		break;
	case 2:
		cout << "������ ";
		break;
	case 3:
		cout << "������ ";
		break;
	case 4:
		cout << "��������� ";
		break;
	case 5:
		cout << "������� ";
		break;
	case 6:
		cout << "�������� ";
		break;
	case 7:
		cout << "������� ";
		break;
	case 8:
		cout << "��������� ";
		break;
	case 9:
		cout << "��������� ";
		break;
	default:
		break;
	}

	switch (b)
	{
	case 1:
	{
		switch (c)
		{
		case 1:
			cout << "����������� �������";
			break;
		case 2:
			cout << "���������� �������";
			break;
		case 3:
			cout << "���������� �������";
			break;
		case 4:
			cout << "������������ �������";
			break;
		case 5:
			cout << "���������� ������� ";
			break;
		case 6:
			cout << "����������� �������";
			break;
		case 7:
			cout << "���������� �������";
			break;
		case 8:
			cout << "������������ �������";
			break;
		case 9:
			cout << "������������ �������";
			break;
		default:
			cout << "������ �������" << endl;
			break;
		}
	}
		break;
	case 2:
		cout << "�������� ";
		break;
	case 3:
		cout << "�������� ";
		break;
	case 4:
		cout << "����� ";
		break;
	case 5:
		cout << "��������� ";
		break;
	case 6:
		cout << "���������� ";
		break;
	case 7:
		cout << "��������� ";
		break;
	case 8:
		cout << "����������� ";
		break;
	case 9:
		cout << "��������� ";
		break;
	default:
		break;
	}
	if (b != 1)
	{
		switch (c)
		{
		case 1:
			cout << "���� �����";
			break;
		case 2:
			cout << "��� ������";
			break;
		case 3:
			cout << "��� ������";
			break;
		case 4:
			cout << "������ ������";
			break;
		case 5:
			cout << "���� ������� ";
			break;
		case 6:
			cout << "����� �������";
			break;
		case 7:
			cout << "���� �������";
			break;
		case 8:
			cout << "������ �������";
			break;
		case 9:
			cout << "������ �������";
			break;
		default:
			cout << "�������" << endl;
			break;
		}
	}
	

	return EXIT_SUCCESS;
}