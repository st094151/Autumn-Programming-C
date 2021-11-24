#include <iostream>

using namespace std;

void swap(int a, int b, int arr[], int arr2[])
{
	int temp = arr[a];
	arr[a] = arr2[b];
	arr2[b] = temp;
}

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;

	cin >> n >> m;

	int* a = new int [n] { 0 };
	int* b = new int [m] { 0 };

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{

			if (a[j] > a[j + 1])
			{
				swap(j, j + 1, a, a);
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m - i - 1; ++j)
		{

			if (b[j] > b[j + 1])
			{
				swap(j, j + 1, b, b);
			}
		}
	}

	int i = 0;
	int j = 0;
	int current = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ((a[i] == b[j]) && (a[i] != current) )
			{
				current = a[i];
				cout << current << " ";
			}
		}
	}

	return EXIT_SUCCESS;
}