#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int x1 = 0; // x1, y1 - координаты ферзя
	int y1 = 0;
	int x2 = 0; // x2, y2 - координаты другой фигуры
	int y2 = 0;


	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;

	if ((x1 == x2) || (y1 == y2))
	{
		cout << "YES" << endl;
	}
	else if ((x1 - x2) * (x1 - x2) == (y1 - y2) * (y1 - y2))// Ферзь на одной диагонали с другой фигурой
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return EXIT_SUCCESS;
}