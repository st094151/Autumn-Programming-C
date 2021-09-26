#include <iostream>
#include <clocale>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	int n = 0;
	int a = 0;// Сотни
	int b = 0;// Десятки
	int c = 0;// Единицы

	cin >> n;
	c = n % 10;
	b = ((n - c) % 100) / 10;
	a = ((n - b - c) % 1000) / 100;

	switch (a)
	{
	case 1:
		cout << "сто ";
		break;
	case 2:
		cout << "двести ";
		break;
	case 3:
		cout << "триста ";
		break;
	case 4:
		cout << "четыреста ";
		break;
	case 5:
		cout << "пятьсот ";
		break;
	case 6:
		cout << "шестьсот ";
		break;
	case 7:
		cout << "семьсот ";
		break;
	case 8:
		cout << "восемьсот ";
		break;
	case 9:
		cout << "девятьсот ";
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
			cout << "одиннадцать бананов";
			break;
		case 2:
			cout << "двенадцать бананов";
			break;
		case 3:
			cout << "тринадцать бананов";
			break;
		case 4:
			cout << "четырнадцать бананов";
			break;
		case 5:
			cout << "пятнадцать бананов ";
			break;
		case 6:
			cout << "шестнадцать бананов";
			break;
		case 7:
			cout << "семнадцать бананов";
			break;
		case 8:
			cout << "восемнадцать бананов";
			break;
		case 9:
			cout << "девятнадцать бананов";
			break;
		default:
			cout << "десять бананов" << endl;
			break;
		}
	}
		break;
	case 2:
		cout << "двадцать ";
		break;
	case 3:
		cout << "тридцать ";
		break;
	case 4:
		cout << "сорок ";
		break;
	case 5:
		cout << "пятьдесят ";
		break;
	case 6:
		cout << "шестьдесят ";
		break;
	case 7:
		cout << "семьдесят ";
		break;
	case 8:
		cout << "восемьдесят ";
		break;
	case 9:
		cout << "девяносто ";
		break;
	default:
		break;
	}
	if (b != 1)
	{
		switch (c)
		{
		case 1:
			cout << "один банан";
			break;
		case 2:
			cout << "два банана";
			break;
		case 3:
			cout << "три банана";
			break;
		case 4:
			cout << "четыре банана";
			break;
		case 5:
			cout << "пять бананов ";
			break;
		case 6:
			cout << "шесть бананов";
			break;
		case 7:
			cout << "семь бананов";
			break;
		case 8:
			cout << "восемь бананов";
			break;
		case 9:
			cout << "девять бананов";
			break;
		default:
			cout << "бананов" << endl;
			break;
		}
	}
	

	return EXIT_SUCCESS;
}