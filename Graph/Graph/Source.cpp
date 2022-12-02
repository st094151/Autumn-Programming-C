#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{

	txCreateWindow(1024, 768, true);

	/*txCircle(300, 300, 30);
	//txTextOut(300, 300, "1", txDC());
	txCircle(600, 600, 30);
	//txTextOut(600, 600, "2", txDC());
	txLine(300, 300, 600, 600, txDC());
	//
	
	Circle v1;

	v1.Setx(100);
	v1.Sety(100);
	Circle v2(300, 300);

	Line e;
	e.Setx1(v1.Getx());
	e.Sety1(v1.Gety());
	e.Setx2(v2.Getx());
	e.Sety2(v2.Gety());

	//txSetFillColor(TX_ORANGE, txDC());
	v1.Show(txDC());
	txTextOut(130, 100, "1", txDC());
	//txSetFillColor(TX_BLUE, txDC());
	v2.Show(txDC());
	txTextOut(330, 300, "2", txDC());
	e.Show(txDC());
	

	Node d1(100, 100, 1, 1);
	Node d2(300, 300, 2, 2);
	Edge e1(d1.Getx(), d1.Gety(), d2.Getx(), d2.Gety(), 2, 0);

	d1.Show(txDC());
	d2.Show(txDC());
	e1.Show(txDC());
*/

	int n = 0;

	cin >> n;

	int** matrix;

	matrix = new int* [n]; 
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> matrix[i][j];
		}
	}
		
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
*/

	Graph* G = new Graph(n, matrix);
	G->Show(txDC());
	G->Colouring();
	G->Show(txDC());

	return EXIT_SUCCESS;
}