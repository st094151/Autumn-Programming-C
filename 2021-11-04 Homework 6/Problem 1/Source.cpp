#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <clocale>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	bool exiting = false;

	int capacity = 2;
	int count = 0;
	int* a = new int [capacity] { 0 };

	while (!exiting)
	{
		system("cls");
		printf("0. Выход из программы. \n");
		printf("1. Вывод текущего состояния массива. \n");
		printf("2. Добавить элемент в конец массива. \n");
		printf("3. Добавить элемент в начало массива. \n");
		printf("4. Удалить элемент из конца массива. \n");
		printf("5. Удалить элемент из начала массива. \n");
		printf("6. Развернуть массив. \n");
		printf("Input your choice : ");

		char c = 0;
		cin >> c;

		switch (c)
		{
		case 27: case 48: //0 + Esc
			exiting = true;
			break;
		case 49: // 1
			for (int i = 0; i < count; ++i)
			{
				cout << a[i] << " ";
			}
			cout << endl;
			system("pause");

			break;
		case 50: // 2
			if (count + 1 == capacity)
			{
				capacity *= 2;
				int* temp = new int[capacity] { 0 };
				for (int i = 0; i < count; ++i)
				{
					temp[i] = a[i];
				}
				delete[] a;
				a = temp;
			}
			cin >> a[count];
			++count;

			break;
		case 51: // 3
			if (count + 1 == capacity)
			{
				capacity *= 2;
				int* temp = new int[capacity] { 0 };
				for (int i = 1; i <= count; ++i)
				{
					temp[i] = a[i - 1];
				}
				delete[] a;
				a = temp;
			}
			else
			{
				int* temp = new int[capacity] { 0 };
				for (int i = 1; i <= count; ++i)
				{
					temp[i] = a[i - 1];
				}
				delete[] a;
				a = temp;
			}
			cin >> a[0];
			++count;

			break; 
		case 52: // 4
			a[count] = 0;

			if (count != 0)
			{
				--count;
			}

			break;
		case 53: // 5
			for (int i = 0; i < count - 1; ++i)
			{
				a[i] = a[i + 1];
			}
			a[count] = 0;

			if (count != 0)
			{
				--count;
			}

			break;
		case 54: //6
			for (int i = 0; i <= count / 2; ++i)
			{
				int temp = 0;
				temp = a[i];

				a[i] = a[count - i - 1];
				a[count - i - 1] = temp;
			}

			break;
		}
	}
	
	delete[] a;
	return EXIT_SUCCESS;
}