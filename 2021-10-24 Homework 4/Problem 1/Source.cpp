#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int sum = 0;// Сумма элементов массива
	bool containnegative = false; //Содержатся ли отрицательные элементы в массиве
	int negativeproduct = 1;// Произведение отрицательных элементов
	int min = 0;
	int max = 0;
	int premax = 0; //Второй по значению элемент
	const int maxlength = 100;
	int a[maxlength] = { 0 };

	cin >> n;

	//Заполнение массива
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	//Вывод массива
	cout << "ARRAY : ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	//Вывод четных элементов массива
	cout << "EVEN : ";
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			cout << a[i] << ' ';
		}
	}
	cout << endl;

	// Сумма элементов массива
	for (int i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	cout << "SUM : " << sum << endl;

	//Произведение отрицательных элементов массива
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

	//Индекс первого минимального элемента
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < a [min])
		{
			min = i;
		}
	}
	cout << "FIRST MIN INDEX : " << min << endl;

	//Второй по значению элементы
	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= a[max])
		{
			premax = max;
			max = i;
		}
		else if ( (a[i] >= a[premax]) || (max == premax) )//Вторая скобка на случай, когда первый элемент максимальный
		{
			premax = i;
		}
	}
	cout << "SECOND MAX : " << a[premax] << endl;

	//Вывод массива в обратном порядке
	cout << "REVERSE : ";
	for (int i = n - 1; i >= 0; --i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	//Вывод элемента массива с нечётными индексами
	cout << "ODD INDEXES : ";
	for (int i = 1; i < n - (n % 2); i += 2)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	return EXIT_SUCCESS;
}